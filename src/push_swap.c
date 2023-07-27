/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:43:01 by sbalk             #+#    #+#             */
/*   Updated: 2023/07/27 18:40:41 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort(t_node **a, t_node **b, int stacksize)
{
	if (stacksize == 2 && !is_list_n_sorted(a, 2, 1))
		sa(a);
	else if (stacksize == 3)
		sort_three(a);
	else if (stacksize == 5)
		sort_five(a, b);
	else
	{
		if (stacksize == 100)
			quicksort_stack(a, b, stacksize, 100);
		else if (stacksize == 500)
			quicksort_stack(a, b, stacksize, 20);
		else if (stacksize < 100)
			quicksort_stack(a, b, stacksize, 2);
		else
			quicksort_stack(a, b, stacksize, 20);
		insertion_sort(a, b);
	}
}


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
	nums = str_to_int_array(argc, argv);
	sorted_nums = list_to_sorted_array(argc, nums);
	a = create_stack(argc, nums, sorted_nums);
	is_stack_unsorted(&a);
	sort(&a, &b, argc);
	
	free(nums);
	free(sorted_nums);
	free_list(&a);
	free_list(&b);
	return (0);
}
