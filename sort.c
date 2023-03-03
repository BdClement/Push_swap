/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:43:29 by clbernar          #+#    #+#             */
/*   Updated: 2023/03/01 14:24:56 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Trie une liste de 3 elements
void	sort_3(t_liste **lst, int max_rank)
{
	if (lstsize(*lst) == 3)
	{
		if (max_rank == (*lst)->rank)
		{
			rotate_family(lst, lst, 1);
			if (check_sorted(*lst) == 1)
				swap_family(lst, lst, 1);
		}
		else if (max_rank == lstlast(*lst)->rank)
		{
			if (check_sorted(*lst) == 1)
				swap_family(lst, lst, 1);
		}
		else
		{
			reverse_rotate_family(lst, lst, 1);
			if (check_sorted(*lst) == 1)
				swap_family(lst, lst, 1);
		}
	}
}

// On pre-trie notre liste en 5 ou 10 parties en fonction du nb de valeurs
// On push chaque parties dans B de maniere croissante
// Jusqu'a conserver les 3 plus grands elements dans A
// Puis on trie nos 3 elements dans A
void	pre_sort_list(t_liste **lst_a, t_liste **lst_b)
{
	int	size;
	int	part;
	int	i;

	i = 1;
	size = lstsize(*lst_a);
	if (size > 100)
		part = size / 10;
	else
		part = size / 5;
	while (lstsize(*lst_a) != 3)
		part_sort(lst_a, lst_b, part * i++, size);
	sort_3(lst_a, size);
}

// Cette fonction push une partie entiere dans B
// On rotate A tant que l'element au dessus n'est pas dans notre partie
// On push tout les elements de la partie dans B
// En mettant les plus grans elements de la partie en bas de B
// Et en conservant les plus petits en haut
void	part_sort(t_liste **lst_a, t_liste **lst_b, int part, int initial_size)
{
	int	size;
	int	slice;

	size = lstsize(*lst_a);
	if (initial_size > 100)
		slice = initial_size / 10;
	else
		slice = initial_size / 5;
	while (lstsize(*lst_a) > size - slice && lstsize(*lst_a) > 3)
	{
		if ((*lst_a)->rank <= part && (*lst_a)->rank < initial_size - 2)
			push(lst_a, lst_b, 'b');
		else
			rotate_family(lst_a, lst_b, 1);
		if (lstsize(*lst_b) > 2 && (*lst_b)->rank >= part - (slice / 2))
		{
			if ((*lst_a)->rank > part && (*lst_a)->rank < initial_size - 2)
				rotate_family(lst_a, lst_b, 3);
			else
				rotate_family(lst_a, lst_b, 2);
		}
	}
}

// Chercher la localisation du plus proche du premier de la liste A
// Soit au debut soit a la fin de la liste B
// En fonction du cas reverse b n fois et push a
// Ou reverse_rotate_b n fois
// Sur le chemin si on trouve lst_a->rank -2 on le push dans A
// Et continue le chemin puis push a + swap a
void	sort_lst_a(t_liste **lst_a, t_liste **lst_b)
{
	while (lstsize(*lst_b) != 0)
	{
		push_closer_back(lst_a, lst_b, (*lst_a)->rank);
		if ((*lst_a)->rank > ((*lst_a)->next)->rank)
			swap_family(lst_a, lst_b, 1);
	}
}

int	*sort_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
	return (tab);
}
