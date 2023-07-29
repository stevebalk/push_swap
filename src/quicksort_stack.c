/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:53:40 by sbalk             #+#    #+#             */
/*   Updated: 2023/07/29 15:53:54 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Returns the smallest index value from the given list */
static int	get_chunk_min_index(t_node *stack)
{
	int min_value;

	min_value = stack->index;
	while (stack != NULL)
	{
		if (stack->index < min_value)
		{
			min_value = stack->index;
		}
		stack = stack->next;
	}
	return (min_value);
}

/* Returns the highest index value from the given list */
static int	get_chunk_max_index(t_node *stack, int chunksize)
{
	int	*sorted_values;
	int	array_size;
	int	ret;

	array_size = copy_list_to_array(stack, &sorted_values);
	quicksort(sorted_values, 0, array_size - 1);
	ret = sorted_values[chunksize - 1];
	free(sorted_values);
	return (ret);
}

/* Calculates and returns the median index of a given chunk */
static int	get_chunk_median(t_node *stack, int chunksize)
{
	int	*sorted_values;
	int	array_size;
	int	ret;

	array_size = copy_list_to_array(stack, &sorted_values);
	quicksort(sorted_values, 0, array_size - 1);
	ret = sorted_values[chunksize / 2 - 1];
	free(sorted_values);
	return (ret);
}

/* Sorting logic for stack quicksort */
static int	sorting_logic(t_node **a, t_node **b, t_qsdata data)
{
	int	i;

	i = 0;
	if ((*a)->index >= data.min && (*a)->index <= data.median)
	{
		if (*b && (*b)->index > data.median)
			rb(b);
		pb(a, b);
		i++;
	}
	else if ((*a)->index > data.median && (*a)->index <= data.max)
	{
		if (*b && (*b)->index > data.median)
			rb(b);
		pb(a, b);
		i++;
	}
	else
	{
		if (*b && (*b)->next && (*b)->index > data.median)
			rr(a, b);
		else
			ra(a);
	}
	return (i);
}

/* Sorts n chunks from a to b, from small to high */
void	quicksort_stack(t_node **a, t_node **b, int size, int chunks)
{
	int	chunksize;
	int	i;
	int	j;
	t_qsdata data;

	i = 0;
	j = 0;
	chunksize = (size / chunks) * 2;
	if (size % chunks != 0)
		chunksize += size % chunks;

	while (j < chunks)
	{
		data.min = get_chunk_min_index(*a);
		data.max = get_chunk_max_index(*a, chunksize);
		data.median = get_chunk_median(*a, chunksize);
		while (i < chunksize)
			i += sorting_logic(a, b, data);
		i = 0;
		chunksize = (size / chunks) * 2;
		j += 2;
	}
}
