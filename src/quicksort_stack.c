/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:53:40 by sbalk             #+#    #+#             */
/*   Updated: 2023/07/26 18:26:51 by sbalk            ###   ########.fr       */
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

static int	sorting_logic(t_node **a, t_node **b, t_qsdata data)
{
	int i;

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
		if (*b && (*b)->index > data.median)
			rr(a, b);
		else
			ra(a);
	}
	return (i);
}

void	quicksort_stack(t_node **a, t_node **b, int size, int chunks)
{
	int	chunksize;
	int i;
	t_qsdata data;

	chunksize = size / chunks;
	i = 0;

	while (chunks)
	{
		data.min = get_chunk_min_index(*a);
		data.max = get_chunk_max_index(*a, chunksize * 2);
		data.median = get_chunk_median(*a, chunksize * 2);
		while (i < chunksize * 2)
			i += sorting_logic(a, b, data);
		i = 0;
		chunks -= 2;
	}
}