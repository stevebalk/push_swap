/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_quicksort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:18:41 by sbalk             #+#    #+#             */
/*   Updated: 2023/07/17 17:16:29 by sbalk            ###   ########.fr       */
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

static void	push_pivot(t_node **a, t_node **b)
{
	pa(a, b);
	rb(b);
}

static int get_median(t_node **stack, int size)
{
	int *nums;
	int i;
	t_node *cur_node;
	int low;
	int high;
	int median;

	i = 0;
	low = 0;
	high = 0;
	nums = malloc(sizeof(int) * size);
	cur_node = *stack;
	if (nums == NULL)
		return (0);
	while (i < size)
	{
		nums[i] = cur_node->index;
		if (nums[i] < low)
			low = nums[i];
		if (nums[i] > high)
			high = nums[i];
		cur_node = cur_node->next;
		i++;
	}
	quicksort(nums, low, high);
	median = nums[size / 2];
	free(nums);
	printf("Median: %d Size: %d\n", median, size);
	return (median);
}

// static int get_pivot(t_node **a, int size)
// {
// 	t_node *cur_node;

// 	cur_node = *a;
// 	while (size)
// 	{
// 		cur_node = cur_node->next;
// 		size--;
// 	}
// 	return cur_node->index;
// }

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
	int moved_b;

	if (size <= 1)
		return ;
	pivot = get_median(a, size);
	moved_b = 0;
	i = 0;
	while (i++ < size)
	{
		if ((*a)->index > pivot)
		{
			pa(a, b);
			moved_b++;
		}
		else if ((*a)->index == pivot)
		{
			push_pivot(a, b);
			moved_b++;
		}
		else
			ra(a);
	}
	// printf("Loop\n");
	// fflush(stdout);
	if (moved_b)
	{
		// rotate_backward(a, moved_b);
		push_larger_half(a, b, moved_b);
		ra(a);
		ps_quicksort(a, b, size - moved_b - 1);
		rotate_backward(a, moved_b);
		ps_quicksort(a, b, moved_b - 1);
		rotate_forward(a, moved_b);
	}
	else
		rotate_backward(a, moved_b);
}