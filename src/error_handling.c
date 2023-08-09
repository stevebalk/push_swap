/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:12:05 by sbalk             #+#    #+#             */
/*   Updated: 2023/08/09 17:07:28 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Free given lists or arrays and exit with 1 */
void	error_free(t_pslist **a, t_pslist **b, int *arr1, int *arr2)
{
	if (a)
		if (a != NULL)
			ps_free_list(a);
	if (b)
		if (b != NULL)
			ps_free_list(b);
	if (arr1)
		if (arr1 != NULL)
			free(arr1);
	if (arr2)
		if (arr2 != NULL)
			free(arr2);
	write(2, "Error", 5);
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

static void	check_one_input(char **str)
{
	char	**input;
	int		size;

	input = ft_split(*str, ' ');
	if (input == NULL)
		error_free(NULL, NULL, NULL, NULL);
	size = str_arr_len(input);
	if (size <= 1 || !is_valid_input(input, size) || is_dup(input, size))
	{
		ft_free_2darray((void **) input, size + 1);
		error_free(NULL, NULL, NULL, NULL);
	}
	if (is_sorted(input, size))
	{
		ft_free_2darray((void **) input, size + 1);
		exit (EXIT_SUCCESS);
	}
	ft_free_2darray((void **) input, size + 1);
}

static void	check_multiple_inputs(char **str, int size)
{
	if (!is_valid_input(str, size) || is_dup(str, size))
		error_free(NULL, NULL, NULL, NULL);
	if (is_sorted(str, size))
		exit (EXIT_SUCCESS);
}

void	error_check(char **str, int size)
{
	if (size == 0)
		exit(EXIT_SUCCESS);
	else if (size == 1)
		check_one_input(str);
	else
		check_multiple_inputs(str, size);
}
