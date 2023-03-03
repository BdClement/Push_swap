/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:45:31 by clbernar          #+#    #+#             */
/*   Updated: 2023/03/01 17:58:02 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_liste
{
	int					content;
	int					rank;
	struct s_liste		*next;
}					t_liste;

// Check list
int		is_only_digit(int argc, char **argv);
int		check_doublons(t_liste *lst);
int		check_and_fill_list(t_liste **lst, char **argv, int argc);
int		check_overflow(const char *nptr);
int		check_sorted(t_liste *lst);

// Fill list
int		is_splitable(char *arg);
int		fill_lst_with_spitable(char *spitable, t_liste **lst);
int		fill_lst(char **argv, t_liste **lst);
void	fill_rank(t_liste **lst);

// Moves
void	swap(t_liste **lst);
void	push(t_liste **lst_a, t_liste **lst_b, char c);
void	rotate(t_liste **lst);
void	reverse_rotate(t_liste **lst);

// Family Moves

void	swap_family(t_liste **lst_a, t_liste **lst_b, int move);
void	rotate_family(t_liste **lst_a, t_liste **lst_b, int move);
void	reverse_rotate_family(t_liste **lst_a, t_liste **lst_b, int move);

// Sort
void	sort_3(t_liste **lst, int max_rank);
int		*sort_tab(int *tab, int size);
void	pre_sort_list(t_liste **lst_a, t_liste **lst_b);
void	sort_lst_a(t_liste **lst_a, t_liste **lst_b);
void	part_sort(t_liste **lst_a, t_liste **lst_b, int start, int end);

// Utils list
t_liste	*lstnew(int content);
t_liste	*lstlast(t_liste *lst);
void	lstadd_back(t_liste **lst, t_liste *new);
void	lstclear(t_liste **lst);
void	lstadd_front(t_liste **lst, t_liste *new);

// Get Closer
int		lstsize(t_liste *lst);// A REPLACER
void	push_closer_back(t_liste **lst_a, t_liste **lst_b, int rank);
int		get_closers_location(t_liste *lst, int rank);
int		closer_is_up(t_liste *lst, int rank);
void	sort_5(t_liste **lst_a, t_liste **lst_b);

#endif
