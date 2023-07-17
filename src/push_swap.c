/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:43:01 by sbalk             #+#    #+#             */
/*   Updated: 2023/07/17 14:42:42 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// static void print_array(int arr[], int size)
// {
// 	printf("Array: \n");
// 	for (int i = 0; i < size; i++)
// 		printf("%i ,", arr[i]);
// 	printf("\n");
// }

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
	// print_array(nums, argc);
	sorted_nums = create_sorted_array(argc, nums);
	// quicksort(nums, 0, argc - 1);
	// print_array(nums, argc);
	a = create_stack(argc, nums, sorted_nums);
	is_stack_unsorted(&a);
	debug_print_stack(a, "A");
	ps_quicksort(&a, &b, argc);
	debug_print_stack(a, "A");
	free_list(&a);
	free_list(&b);
	return (0);
}
