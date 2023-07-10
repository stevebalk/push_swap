/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:43:01 by sbalk             #+#    #+#             */
/*   Updated: 2023/07/10 16:18:51 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		*nums;
	int		*sorted_nums;

	b = NULL;
	argc--;
	argv++;
	input_check(argv, argc);
	nums = convert_to_int_array(argc, argv);
	sorted_nums = create_sorted_array(argc, nums);
	a = create_stack(argc, nums, sorted_nums);
	is_stack_unsorted(&a);
	free_list(&a);
	free_list(&b);
	return (0);
}
