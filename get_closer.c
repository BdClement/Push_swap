/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_closer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:42:53 by clbernar          #+#    #+#             */
/*   Updated: 2023/03/02 18:52:38 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Cette fonction va chercher le plus proche du premier de A
// Si sur le chemin le deuxieme plus proche est trouve il est envoye egalement
void	push_closer_back(t_liste **lst_a, t_liste **lst_b, int rank)
{
	int	i;
	int	location;

	i = 0;
	location = get_closers_location(*lst_b, (*lst_a)->rank);
	if (closer_is_up(*lst_b, (*lst_a)->rank) == 1)
	{
		while (i++ < location)
		{
			if ((*lst_b)->rank == rank - 2)
				push(lst_a, lst_b, 'a');
			if ((*lst_b)->rank != rank - 1)
				rotate_family(lst_a, lst_b, 2);
		}
	}
	else
	{
		while (i++ < location)
		{
			reverse_rotate_family(lst_a, lst_b, 2);
			if ((*lst_b)->rank == rank - 2)
				push(lst_a, lst_b, 'a');
		}
	}
	push(lst_a, lst_b, 'a');
}

// Trouve le nombre de fois qu'il faut pour placer le plus proche en haut de B
// Pour le push dans A
int	get_closers_location(t_liste *lst, int rank)
{
	int		i;
	int		down;
	int		side;

	i = 0;
	side = closer_is_up(lst, rank);
	down = -1;
	while (lst != NULL)
	{
		if (side == 1)
		{
			if (lst->rank == rank - 1)
				return (i);
			i++;
		}
		if (side == 0)
		{
			if (lst->rank == rank - 1)
				down = 1;
			if (down == 1)
				i++;
		}
		lst = lst->next;
	}
	return (i);
}

// Determine si le chemin doit s'effectuer a partir de debut de la liste
// Ou de la fin
int	closer_is_up(t_liste *lst, int rank)
{
	int		i;
	int		size;

	i = 0;
	size = lstsize(lst);
	while (lst != NULL)
	{
		if (lst->rank == rank -1)
		{
			if (i < size / 2)
				return (1);
		}
		i++;
		lst = lst->next;
	}
	return (0);
}

// A REPLACER
int	lstsize(t_liste *lst)
{
	int		i;
	t_liste	*tmp;

	i = 0;
	if (lst != NULL)
	{
		tmp = lst;
		while (tmp != NULL)
		{
			i++;
			tmp = tmp->next;
		}
	}
	return (i);
}

void	sort_5(t_liste **lst_a, t_liste **lst_b)
{
	int	size;

	size = lstsize(*lst_a);
	fill_rank(lst_a);
	if (lstsize(*lst_a) == 2)
	{
		swap_family(lst_a, lst_b, 1);
		return ;
	}
	while (lstsize(*lst_a) != 3)
	{
		if ((*lst_a)->rank > size - 3)
			rotate_family(lst_a, lst_b, 1);
		else
			push(lst_a, lst_b, 'b');
	}
	sort_3(lst_a, size);
	if (lstsize(*lst_b) == 2 && (*lst_b)->rank < ((*lst_b)->next)->rank)
		swap_family(lst_a, lst_a, 2);
	while (lstsize(*lst_a) != size)
		push(lst_a, lst_b, 'a');
}
