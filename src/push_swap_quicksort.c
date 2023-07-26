/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_quicksort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:18:41 by sbalk             #+#    #+#             */
/*   Updated: 2023/07/26 13:41:50 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

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

static int	get_next_pos(t_node **src, int index)
{
	int	i;
	int	j;
	int	size;
	int *array;

	i = 0;
	j = 1;
	size = copy_list_to_array(*src, &array);
	while (i < size)
	{
		if (array[i] == index)
			break ;
		i++;
	}
	while (j < size)
	{
		if (array[size - j] == index)
			break ;
		j++;
	}
	if (i <= j + 1)
		return (i);
	return (j * - 1);
}

/* Pushed next desired index and one index below if possible */
static int	smart_push(t_node **a, t_node **b, int next_pos, int lower_index)
{
	int	i;
	int	pushed_lower;

	i = 0;
	pushed_lower = 0;
	while (i++ < ft_abs(next_pos))
	{
		if ((*a)->index == lower_index)
		{
			pa(a, b);
			ra(a);
			pushed_lower = 1;
			if (next_pos < 0)
				next_pos--;
		}
		else if (next_pos < 0)
			rrb(b);
		else
			rb(b);
	}
	pa(a, b);
	if (pushed_lower)
		rra(a);
	return (1 + pushed_lower);
}

void	insertion_sort(t_node **a, t_node **b)
{
	int	*sorted_array;
	int	array_size;
	int	next_pos;
	int	offset;

	array_size = copy_list_to_array(*b, &sorted_array);
	quicksort(sorted_array, 0, array_size - 1);
	offset = 0;

	while ((*b) != NULL)
	{
		next_pos = get_next_pos(b, sorted_array[array_size - 1 - offset]);
		if ((*b)->next != NULL)
			offset += smart_push(a, b, next_pos, sorted_array[array_size - 2 - offset]);
		else
			pa(a, b);
		offset++;
		*b = (*b)->next;
	}
	free(sorted_array);
}

void	quicksort_stack(t_node **src, t_node **dst, int size, int chunks)
{
	int	chunksize;
	int i;
	int min;
	int max;
	int median;

	chunksize = size / chunks;
	i = 0;

	while (chunks)
	{
		min = get_chunk_min_index(*src);
		max = get_chunk_max_index(*src, chunksize * 2);
		median = get_chunk_median(*src, chunksize * 2);
		while (i < chunksize * 2)
		{
			if ((*src)->index >= min && (*src)->index <= median)
			{
				if (*dst && (*dst)->index > median)
					rb(dst);
				pb(src, dst);
				i++;
			}
			else if ((*src)->index > median && (*src)->index <= max)
			{
				if (*dst && (*dst)->index > median)
					rb(dst);
				pb(src, dst);
				i++;
			}
			else
			{
				if (*dst && (*dst)->index > median)
					rr(src, dst);
				else
					ra(src);
			}
		}
		i = 0;
		chunks -= 2;
	}
}
