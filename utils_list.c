/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:07:23 by clbernar          #+#    #+#             */
/*   Updated: 2023/03/01 14:07:55 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_liste	*lstnew(int content)
{
	t_liste	*new;

	new = (t_liste *)malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->rank = -1;
	new->next = NULL;
	return (new);
}

t_liste	*lstlast(t_liste *lst)
{
	t_liste	*tmp;
	t_liste	*last;

	tmp = lst;
	last = lst;
	while (tmp != NULL)
	{
		last = tmp;
		tmp = tmp->next;
	}
	return (last);
}

void	lstadd_front(t_liste **lst, t_liste *new)
{
	if (new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}

void	lstadd_back(t_liste **lst, t_liste *new)
{
	t_liste	*tmp;

	if (*lst != NULL)
	{
		tmp = lstlast(*lst);
		tmp->next = new;
	}
	else
		*lst = new;
}

void	lstclear(t_liste **lst)
{
	t_liste	*tmp;

	if (lst == NULL)
		return ;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		free(*lst);
		(*lst) = tmp;
	}
	*lst = NULL;
}
