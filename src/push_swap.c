/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:43:01 by sbalk             #+#    #+#             */
/*   Updated: 2023/07/29 18:20:39 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			quicksort_stack(a, b, stacksize, 10);
		else if (stacksize == 500)
			quicksort_stack(a, b, stacksize, 20);
		else if (stacksize < 100)
			quicksort_stack(a, b, stacksize, 2);
		else
			quicksort_stack(a, b, stacksize, 20);
		insertion_sort(a, b);
	}
	free_list(a);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	argc--;
	argv++;
	error_check(argv, argc);
	create_stack(&a, argv, argc);
	sort(&a, &b, argc);
	return (0);
}
