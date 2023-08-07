/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:42:58 by sbalk             #+#    #+#             */
/*   Updated: 2023/08/07 14:56:09 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_pslist
{
	int				value;
	int				index;
	struct s_pslist	*next;
}	t_pslist;

typedef struct s_qsdata
{
	int	min;
	int	max;
	int	median;
}	t_qsdata;

/* String functions */

void		putstr(char	*str);
int			str_arr_len(char **arr);

/* Error handling */

int			is_dup(char **str, int size);
int			is_sorted(char **str, int size);
int			is_valid_input(char **str, int size);
void		error_check(char **str, int size);
void		error_free(t_pslist **a, t_pslist **b, int *arr1, int *arr2);

/* index functions */

int			*str_to_int_array(t_pslist **a, char **arr, int size);

/* Sorting functions */

int			get_next_pos(t_pslist **src, int index);
void		quicksort(int arr[], int low, int high);
void		sort_three(t_pslist **a);
void		sort_five(t_pslist **a, t_pslist **b);
void		quicksort_stack(t_pslist **src, t_pslist **dst, int size, int chunks);
void		insertion_sort(t_pslist **a, t_pslist **b);

/* List functions */

t_pslist	*create_node(int value);
int			create_stack(t_pslist **a, char **arr, int size);
int			copy_list_to_array(t_pslist *src, int **dst);
void		free_list(t_pslist **head);
int			get_list_size(t_pslist *stack);
int			is_list_n_sorted(t_pslist **stack, int len, int dir);

/* Push swap functions */

void		pa(t_pslist **a, t_pslist **b);
void		pb(t_pslist **a, t_pslist **b);
void		ra(t_pslist **stack);
void		rb(t_pslist **stack);
void		rr(t_pslist **a, t_pslist **b);
void		rra(t_pslist **a);
void		rrb(t_pslist **b);
void		rrr(t_pslist **a, t_pslist **b);
void		sa(t_pslist **a);
void		sb(t_pslist **b);
void		ss(t_pslist **a, t_pslist **b);

#endif