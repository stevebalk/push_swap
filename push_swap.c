/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:43:01 by sbalk             #+#    #+#             */
/*   Updated: 2023/06/21 12:44:32 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"
// #include "error_handling.c"
// #include "utils.c"


int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	argc--;
	argv++;
	b = NULL;
	input_check(argv, argc);
	a = create_stack(argc, argv);
	is_stack_unsorted(a);
	debug_print_stack(a, "A");
	pa(a, b);
	debug_print_stack(a, "A");
	debug_print_stack(b, "B");
	a = free_list(a);
	return (0);
}
