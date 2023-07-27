/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:31:58 by sbalk             #+#    #+#             */
/*   Updated: 2023/07/27 18:39:47 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	copy_int_array(int **dst, int *src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		*(*dst + i) = src[i];
		i++;
	}
}

void	sort_int_array(int **array, int size)
{
	int j;
	int temp;

	j = 0;
	while (size)
	{
		while (j < size - 1)
		{
			if (*(*array + j) > *(*array + j + 1))
			{
				temp = *(*array + j + 1);
				*(*array + j + 1) = *(*array + j);
				*(*array + j) = temp;
			}
			j++;
		}
		j = 0;
		size--;
	}
}

int	*str_to_int_array(int size, char **list)
{
	int	*ret;
	int	i;

	ret = malloc(size * sizeof(int));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ret[i] = ft_atoi(list[i]);
		i++;
	}
	return (ret);
}

int	*list_to_sorted_array(int size, int *list)
{
	int	*sorted_lst;

	sorted_lst = malloc(size * sizeof(int));
	if (!sorted_lst)
		return (NULL);
	copy_int_array(&sorted_lst, list, size);
	sort_int_array(&sorted_lst, size);
	return sorted_lst;
}