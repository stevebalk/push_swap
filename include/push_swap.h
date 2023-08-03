/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:42:58 by sbalk             #+#    #+#             */
/*   Updated: 2023/08/02 18:13:50 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "printf.h"
# include "libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_qsdata
{
	int	min;
	int	max;
	int	median;
}	t_qsdata;

/* Utility */

void	putstr(char	*str);

// void	debug_print_stack(t_node *stack, char *name); // DELETE LATER!!!

/* Error handling */

void	error_check(char **str, int size);
void	error_free(t_node **a, t_node **b, int *arr1, int *arr2);

/* index functions */

int		*str_to_int_array(t_node **a, char **arr, int size);

/* Sorting functions */

int		get_next_pos(t_node **src, int index);
void	quicksort(int arr[], int low, int high);
void	sort_three(t_node **a);
void	sort_five(t_node **a, t_node **b);
void	quicksort_stack(t_node **src, t_node **dst, int size, int chunks);
void	insertion_sort(t_node **a, t_node **b);

/* List functions */

t_node	*create_node(int value);
void	create_stack(t_node **a, char **arr, int size);
int		copy_list_to_array(t_node *src, int **dst);
void	free_list(t_node **head);
int		get_list_size(t_node *stack);
int		is_list_n_sorted(t_node **stack, int len, int dir);

/* Push swap functions */

void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	ra(t_node **stack);
void	rb(t_node **stack);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);

#endif