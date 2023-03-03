/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:24:31 by clbernar          #+#    #+#             */
/*   Updated: 2023/03/03 14:24:59 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Verifie si il n'y a que des nombres dans les arguments
// Accepte seulement un - devant les nombres, les nombres et les espaces
int	is_only_digit(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j + 1]) == 1 && argv[i][j] == '-')
				j++;
			if (ft_isdigit(argv[i][j]) == 0 && argv[i][j] != ' ')
				return (1);
			j++;
		}
		i++;
	}
	i = 1;
	return (0);
}

int	check_doublons(t_liste *lst)
{
	t_liste	*tmp;

	while (lst != NULL)
	{
		tmp = lst->next;
		while (tmp != NULL)
		{
			if (tmp->content == lst->content)
				return (1);
			tmp = tmp->next;
		}
		lst = lst->next;
	}
	return (0);
}

int	check_sorted(t_liste *lst)
{
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (0);
		if (lst->content > ((lst->next)->content))
			return (1);
		lst = lst->next;
	}
	return (0);
}

//Check si la chaine donnee depassera les limites de int
//Chiffre par chiffre des lors qu'on depasse les limites
// On renvoie 1 synomyme de ecrire error sur la sortie d'erreur
int	check_overflow(const char *nptr)
{
	long int	value;
	int			sign;

	value = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	if (ft_strlen(nptr) == 0 || ft_isdigit(*nptr) == 0)
		return (1);
	while (*nptr >= '0' && *nptr <= '9')
	{
		value = value * 10 + (*nptr - 48);
		nptr++;
		if (value > INT_MAX || value < INT_MIN)
			return (1);
	}
	return (0);
}

// La fonction utilise toutes les fonctions de check et remplie si tout est ok
// Free la liste si besoin et ecrit sur la sortie d'erreur s'il le faut
int	check_and_fill_list(t_liste **lst, char **argv, int argc)
{
	if (is_only_digit(argc, argv) == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	else if (fill_lst(argv, lst) == 1 || check_doublons(*lst) == 1)
	{
		lstclear(lst);
		write(2, "Error\n", 6);
		return (1);
	}
	else if (check_sorted(*lst) == 0)
		lstclear(lst);
	return (0);
}
