/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:12:05 by sbalk             #+#    #+#             */
/*   Updated: 2023/07/29 16:40:13 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Checks for duplicates */
static int	is_dup(char **str, int size)
{
	int	*nums;
	int	i;

	i = 0;
	nums = str_to_int_array(NULL, str, size);
	quicksort(nums, 0, size - 1);
	while (i < size - 1)
	{
		if (nums[i] == nums[i + 1])
		{
			free(nums);
			return (1);
		}
		i++;
	}
	free(nums);
	return (0);
}

/* Checks if input is sorted */
static int	is_sorted(char **str, int size)
{
	int	*nums;
	int	i;

	i = 0;
	nums = str_to_int_array(NULL, str, size);
	while (i < size - 1)
	{
		if (nums[i] > nums[i + 1])
		{
			free(nums);
			return (0);
		}
		i++;
	}
	free(nums);
	return (1);
}

/* Checks if only valid input was given*/
static int	is_valid_input(char **str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (*str == NULL || !is_int(*str))
		{
			return (0);
		}
		str++;
		i++;
	}
	return (1);
}

void	error_check(char **str, int size)
{
	if (!is_valid_input(str, size) || is_dup(str, size))
	{
		putstr("Error\n");
		exit (1);
	}
	if (size <= 1 || is_sorted(str, size))
		exit (0);
}

/* Free given lists or arrays and exit with 1 */
void	error_free(t_node **a, t_node **b, int *arr1, int *arr2)
{
	if (a)
		free_list(a);
	if (b)
		free_list(b);
	if (arr1)
		free(arr1);
	if (arr2)
		free(arr2);
	exit(1);
}
