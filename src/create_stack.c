/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 14:26:20 by sbalk             #+#    #+#             */
/*   Updated: 2023/07/29 16:02:51 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*str_to_int_array(t_node **a, char **arr, int size)
{
	int	*ret;
	int	i;

	ret = malloc(size * sizeof(int));
	if (!ret)
		error_free(a, NULL, NULL, NULL);
	i = 0;
	while (i < size)
	{
		ret[i] = ft_atoi(arr[i]);
		i++;
	}
	return (ret);
}

static void	set_index(t_node **a, int *arr, int size)
{
	int		i;
	t_node	*cur_node;
	
	i = 0;
	quicksort(arr, 0, size - 1);
	cur_node = *a;
	while (cur_node)
	{
		while (i < size)
		{
			if (arr[i] == cur_node->value)
				cur_node->index = i;
			i++;
		}
		cur_node = cur_node->next;
		i = 0;
	}
	free(arr);
}

void	create_stack(t_node **a, char **arr, int size)
{
	int		*num_arr;
	t_node	*head_node;
	int		i;

	num_arr = str_to_int_array(a, arr, size);
	i = 0;
	while (i < size)
	{
		if (!*a)
		{
			*a = create_node(num_arr[i]);
			head_node = *a;
		}
		else
		{
			(*a)->next = create_node(num_arr[i]);
			(*a) = (*a)->next;
		}
		if (*a == NULL)
			error_free(a, NULL, num_arr, NULL);
		i++;
	}
	*a = head_node;
	set_index(a, num_arr, size);
}