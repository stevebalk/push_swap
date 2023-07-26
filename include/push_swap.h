/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:42:58 by sbalk             #+#    #+#             */
/*   Updated: 2023/07/26 12:41:37 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_node
{
	int				value; // Useless???
	int				index;
	struct s_node	*next;
}	t_node;

/* Utility */

int		is_digit(char ch);
void	putstr(char	*str);
ssize_t	ft_atoi(const char *str);
void	debug_print_stack(t_node *stack, char *name); // DELETE LATER!!!

/* Error handling */

void	input_check(char **str, int size);
void	is_stack_unsorted(t_node **head);

/* index functions */

int		*convert_to_int_array(int size, char **list);
int		*create_sorted_array(int size, int *list);

/* Sorting functions */

void	quicksort(int arr[], int low, int high);
void	quicksort_stack(t_node **src, t_node **dst, int size, int chunks);
void	insertion_sort(t_node **a, t_node **b);

/* List functions */

t_node	*create_node(int value, int *sorted_array, int size);
t_node	*create_stack(int size, int *nums, int *sorted_nums);
t_node	*get_last_node(t_node *head);
int		copy_list_to_array(t_node *src, int **dst);
void	free_list(t_node **head);
int		get_list_size(t_node *stack);

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