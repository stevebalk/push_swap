/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:53:50 by sbalk             #+#    #+#             */
/*   Updated: 2023/08/07 14:25:11 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_next_pos(t_pslist **src, int index)
{
	int	i;
	int	j;
	int	size;
	int	*array;

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
	free(array);
	if (i <= j + 1)
		return (i);
	return (j * -1);
}

/* Push next desired index and one index below if possible */
static int	smart_push(t_pslist **a, t_pslist **b, int next_pos, int lower_idx)
{
	int	i;
	int	pushed_lower;

	i = 0;
	pushed_lower = 0;
	while (i++ < ft_abs(next_pos))
	{
		if ((*b)->index == lower_idx)
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
	return (pushed_lower);
}

void	insertion_sort(t_pslist **a, t_pslist **b)
{
	int	*sort_arr;
	int	size;
	int	next_pos;
	int	offset;

	size = copy_list_to_array(*b, &sort_arr);
	quicksort(sort_arr, 0, size - 1);
	offset = 0;
	while (*b)
	{
		next_pos = get_next_pos(b, sort_arr[size - 1 - offset]);
		if ((*b)->next)
			offset += smart_push(a, b, next_pos, sort_arr[size - 2 - offset]);
		else
			pa(a, b);
		offset++;
	}
	free(sort_arr);
}
