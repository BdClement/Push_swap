/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:04:22 by clbernar          #+#    #+#             */
/*   Updated: 2023/03/01 14:11:34 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_liste **lst)
{
	t_liste	*tmp;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	tmp = (*lst)->next;
	(*lst)->next = tmp->next;
	tmp->next = *lst;
	*lst = tmp;
}

void	push(t_liste **lst_a, t_liste **lst_b, char c)
{
	t_liste	*tmp;

	if (c == 'b' && *lst_a != NULL)
	{
		tmp = *lst_a;
		*lst_a = (*lst_a)->next;
		lstadd_front(lst_b, tmp);
		write(1, "pb\n", 3);
	}
	else if (c == 'a' && *lst_b != NULL)
	{
		tmp = *lst_b;
		*lst_b = (*lst_b)->next;
		lstadd_front(lst_a, tmp);
		write(1, "pa\n", 3);
	}
}

void	rotate(t_liste **lst)
{
	t_liste	*last;
	t_liste	*tmp;

	if ((*lst)->next != NULL)
	{
		tmp = *lst;
		last = lstlast(*lst);
		*lst = (*lst)->next;
		last->next = tmp;
		tmp->next = NULL;
	}
}

void	reverse_rotate(t_liste **lst)
{
	t_liste	*tmp;
	t_liste	*last;

	if ((*lst)->next != NULL)
	{
		tmp = *lst;
		last = lstlast(*lst);
		while (tmp->next != last)
			tmp = tmp->next;
		tmp->next = NULL;
		last->next = *lst;
		*lst = last;
	}
}
