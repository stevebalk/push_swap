/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:43:01 by sbalk             #+#    #+#             */
/*   Updated: 2023/06/22 16:25:51 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	b = NULL;
	argc--;
	argv++;
	input_check(argv, argc);
	a = create_stack(argc, argv);
	is_stack_unsorted(&a);
	debug_print_stack(a, "A");
	// pa(&a, &b);
	// ra(&a);
	// rra(&a);
	sa(&a);
	debug_print_stack(a, "A");
	debug_print_stack(b, "B");
	free_list(&a);
	free_list(&b);
	return (0);
}
