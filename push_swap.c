/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:59:59 by clbernar          #+#    #+#             */
/*   Updated: 2023/03/03 14:22:58 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_liste	*lst_a;
	t_liste	*lst_b;

	lst_a = NULL;
	lst_b = NULL;
	if (argc != 1)
	{
		if (check_and_fill_list(&lst_a, argv, argc) == 0)
		{
			if (check_sorted(lst_a) == 0)
				return (0);
			if (lstsize(lst_a) <= 5)
			{
				sort_5(&lst_a, &lst_b);
				lstclear(&lst_a);
				return (0);
			}
			pre_sort_list(&lst_a, &lst_b);
			sort_lst_a(&lst_a, &lst_b);
			lstclear(&lst_a);
		}
	}
	return (0);
}
