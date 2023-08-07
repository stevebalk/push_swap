/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 14:26:20 by sbalk             #+#    #+#             */
/*   Updated: 2023/08/07 14:55:26 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*str_to_int_array(t_pslist **a, char **arr, int size)
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

static void	set_index(t_pslist **a, int *arr, int size)
{
	int		i;
	t_pslist	*cur_node;

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

static void	multiple_input_create(t_pslist **a, char **arr, int size)
{
	int		*num_arr;
	t_pslist	*head_node;
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

static int	single_input_create(t_pslist **a, char *arr)
{
	char	**input;
	int		size;

	input = ft_split(arr, ' ');
	if (input == NULL)
		error_free(NULL, NULL, NULL, NULL);
	size = str_arr_len(input);
	multiple_input_create(a, input, size);
	ft_free_2darray((void **) input, size + 1);
	return size;
}

int	create_stack(t_pslist **a, char **arr, int size)
{
	if (size == 1)
		size = single_input_create(a, arr[0]);
	else
		multiple_input_create(a, arr, size);
	return size;
}
