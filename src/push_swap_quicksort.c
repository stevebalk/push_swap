/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_quicksort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:18:41 by sbalk             #+#    #+#             */
/*   Updated: 2023/07/12 18:27:46 by sbalk            ###   ########.fr       */
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

int	get_median(t_node **a, int size)
{
	int i;
	int sum;
	t_node *cur_node;

	sum = 0;
	i = 0;
	cur_node = *a;
	while (i++ < size)
	{
		sum += cur_node->index;
		cur_node = cur_node->next;
	}
	return (sum / 2);
}

int get_pivot(t_node **a, int size)
{
	t_node *cur_node;

	cur_node = *a;
	while (size > 1)
	{
		cur_node = cur_node->next;
		size--;
	}
	return cur_node->index;
}

void	ps_quicksort(t_node **a, t_node **b, int size)
{
	int	i;
	int median;
	int top_half_len;

	if (size <= 1)
		return ;
	median = get_pivot(a, size);
	top_half_len = 0;
	i = 0;
	while (i++ < size)
	{
		if ((*a)->index > median)
		{
			pa(a, b);
			top_half_len++;
		}
		else
			ra(a);
	}
	push_larger_half(a, b, top_half_len);
	ps_quicksort(a, b, top_half_len);
	rotate_forward(a, top_half_len);
	ps_quicksort(a, b, size - top_half_len);
	rotate_backward(a, top_half_len);
}