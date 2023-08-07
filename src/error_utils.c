/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:51:14 by sbalk             #+#    #+#             */
/*   Updated: 2023/08/07 13:53:12 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Checks for duplicates */
int	is_dup(char **str, int size)
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
int	is_sorted(char **str, int size)
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
int	is_valid_input(char **str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (*str == NULL || !ft_is_str_int(*str))
		{
			return (0);
		}
		str++;
		i++;
	}
	return (1);
}