/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:45:42 by clbernar          #+#    #+#             */
/*   Updated: 2023/03/01 14:15:12 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Verifie si l'argument doit etre envoye a split c'est a dire qu'apres x espaces
//le potentiel signe -, et la suite de chiffre, la chaine n'est pas finie
int	is_splitable(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] == ' ' || arg[i] == '-')
		i++;
	while (ft_isdigit(arg[i]) == 1)
		i++;
	if (arg[i] != '\0')
		return (1);
	return (0);
}

//Split un argument qui doit l'etre et remplie la liste avec
//chaque element spliter passe a atoi
// Puis free le tableau renvoyer par la fonction split
int	fill_lst_with_spitable(char *spitable, t_liste **lst)
{
	char	**tab;
	int		i;
	t_liste	*new;

	i = 0;
	tab = ft_split(spitable, ' ');
	while (tab[i])
	{
		if (check_overflow(tab[i]) == 1)
		{
			while (tab[i])
				free(tab[i++]);
			free(tab);
			return (1);
		}
		new = lstnew(ft_atoi(tab[i]));
		lstadd_back(lst, new);
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

// Remplie la liste avec les elements recus en arguments
int	fill_lst(char **argv, t_liste **lst)
{
	int		i;
	t_liste	*new;

	i = 1;
	while (argv[i])
	{
		if (is_splitable(argv[i]) == 0)
		{
			if (check_overflow(argv[i]) == 1)
				return (1);
			new = lstnew(ft_atoi(argv[i]));
			lstadd_back(lst, new);
		}
		else
		{
			if (fill_lst_with_spitable(argv[i], lst) == 1)
				return (1);
		}
		i++;
	}
	fill_rank(lst);
	return (0);
}

// La fonction remplie la donnee rank de ma structure avec la place
// finale qu'occupera chaque maillon de la liste
void	fill_rank(t_liste **lst)
{
	t_liste	*tmp;
	int		*tab;
	int		i;

	tmp = *lst;
	i = 0;
	tab = malloc(sizeof(int) * lstsize(*lst));
	while (tmp != NULL)
	{
		tab[i++] = tmp->content;
		tmp = tmp->next;
	}
	tab = sort_tab(tab, lstsize(*lst));
	tmp = *lst;
	while (tmp != NULL)
	{
		i = 0;
		while (tab[i] != tmp->content)
			i++;
		tmp->rank = i + 1;
		tmp = tmp->next;
	}
	free(tab);
}
