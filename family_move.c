/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   family_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:14:25 by clbernar          #+#    #+#             */
/*   Updated: 2023/03/01 14:16:38 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Le int move sert a indiquer si le swap est un sa sb ou ss
// 1 = sa
// 2 = sb
// 3 = ss
void	swap_family(t_liste **lst_a, t_liste **lst_b, int move)
{
	if (move == 1)
	{
		swap(lst_a);
		write(1, "sa\n", 3);
	}
	else if (move == 2)
	{
		swap(lst_b);
		write(1, "sb\n", 3);
	}
	else if (move == 3)
	{
		swap(lst_a);
		swap(lst_b);
		write(1, "ss\n", 3);
	}
}

void	rotate_family(t_liste **lst_a, t_liste **lst_b, int move)
{
	if (move == 1)
	{
		rotate(lst_a);
		write(1, "ra\n", 3);
	}
	else if (move == 2)
	{
		rotate(lst_b);
		write(1, "rb\n", 3);
	}
	else if (move == 3)
	{
		rotate(lst_a);
		rotate(lst_b);
		write(1, "rr\n", 3);
	}
}

void	reverse_rotate_family(t_liste **lst_a, t_liste **lst_b, int move)
{
	if (move == 1)
	{
		reverse_rotate(lst_a);
		write(1, "rra\n", 4);
	}
	else if (move == 2)
	{
		reverse_rotate(lst_b);
		write(1, "rrb\n", 4);
	}
	else if (move == 3)
	{
		reverse_rotate(lst_a);
		reverse_rotate(lst_b);
		write(1, "rrr\n", 4);
	}
}
