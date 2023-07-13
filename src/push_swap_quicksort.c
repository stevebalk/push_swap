/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_quicksort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:18:41 by sbalk             #+#    #+#             */
/*   Updated: 2023/07/13 18:08:02 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_larger_half(t_node **a, t_node **b, int size)
{
	while (size--)
		pb(a, b);
}

static void	rotate_forward(t_node **a, int steps)
{
	while (steps--)
		ra(a);
}

static void	rotate_backward(t_node **a, int steps)
{
	while (steps--)
		rra(a);
}

static int get_pivot(t_node **a, int size)
{
	t_node *cur_node;

	cur_node = *a;
	while (size)
	{
		cur_node = cur_node->next;
		size--;
	}
	return cur_node->index;
}

// static int is_sorted(t_node **stack, int pivot, int size)
// {
// 	t_node *cur_node;

// 	cur_node = *stack;
// 	while (size--)
// 	{
// 		if (cur_node->index > pivot)
// 			return (0);
// 		cur_node = cur_node->next;
// 	}
// 	return (1);
// }

void	ps_quicksort(t_node **a, t_node **b, int size)
{
	int	i;
	int pivot;
	int top_half_len;

	if (size == 1)
		return ;
	pivot = get_pivot(a, size);
	top_half_len = 0;
	i = 0;
	while (i++ < size)
	{
		if ((*a)->index > pivot)
		{
			pa(a, b);
			top_half_len++;
		}
		else
			ra(a);
	}
	printf("Loop\n");
	fflush(stdout);
	if (top_half_len > 0)
	{
		rotate_backward(a, size - top_half_len);
		push_larger_half(a, b, top_half_len);
		ps_quicksort(a, b, top_half_len);
		rotate_forward(a, size - top_half_len);
		ps_quicksort(a, b, size - top_half_len);
		rotate_backward(a, top_half_len);
	}
	else
	{
		ps_quicksort(a, b, size - 1);
		rotate_backward(a, top_half_len);
	}
}