/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_quicksort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:18:41 by sbalk             #+#    #+#             */
/*   Updated: 2023/07/25 18:55:18 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/* Returns the smallest index value from the given list */
static int	get_list_min_index(t_node *stack)
{
	int min_value;

	min_value = stack->index;
	while (stack->next != NULL)
		if (stack->index < min_value)
		{
			min_value = stack->index;
			stack = stack->next;
		}
	return (min_value);
}

/* Returns the highest index value from the given list */
static int	get_list_max_index(t_node *stack)
{
	int max_value;

	max_value = stack->index;
	while (stack->next != NULL)
		if (stack->index > max_value)
		{
			max_value = stack->index;
			stack = stack->next;
		}
	return (max_value);
}


int	get_chunk_median(t_node *stack, int chunksize)
{
	int *sorted_values;
	int array_size;

	array_size = copy_list_to_array(stack, &sorted_values);
	quicksort(sorted_values, 0, array_size - 1);
	return (sorted_values[chunksize / 2 - 1]);
}

void	quicksort_stack(t_node **src, t_node **dst, int size, int chunks)
{
	int	chunksize;
	int chunk;
	int i;
	int min;
	int max;
	int median;

	chunksize = size / chunks;
	chunk = 0;
	i = 0;

	while (chunks)
	{
		min = get_list_min_index(src);
		max = get_list_max_index(src);
		median = get_chunk_median(src, chunksize * 2);
		while (i < chunksize * 2);
		{
			if ((*src)->index >= min && (*src)->index <= median)
			{
				if ((*dst) != NULL && (*dst)->index > median)
					rb(dst);
				pb(src, dst);
				i++;
			}
			else if ((*src)->index > median && (*src)->index <= max)
			{
				if ((*dst) != NULL && (*dst)->index > median)
					rb(dst);
				pb(src, dst);
				i++;
			}
			else
			{
				if ((*dst) != NULL && (*dst)->index > median)
					rr(src, dst);
				else:
					ra(src);
			}
		}
		i = 0;
	}
	chunks -= 2;
}

int	get_next_pos(t_node **src, int index)
{
	int	i;
	int	j;
	int	size;
	int *array;

	i = 0;
	j = 0;
	size = copy_list_to_array(*src, &array);
	while (i < size)
	{
		if (array[i] == index)
			break ;
		i++;
	}
	while (j < size)
		if (array[size])

}

void	insertion_sort(t_node **src, t_node **dst)
{
	int	*sorted_array;
	int	array_size;
	int	next_pos;
	int	offset;

	array_size = copy_list_to_array(src, dst);
	quicksort(sorted_array, 0, array_size - 1);
	offset = 0;

	while ((*src) != NULL)
	{
		next_pos = get_next_pos(src, sorted_array[array_size - 1 - offset]);
		if ((*src)->next != NULL)
			offset += smart_push(src, next_pos, sorted_array[array_size - 2 - offset]);
		else
			pa(src, dst);
		offset++;
	}
}