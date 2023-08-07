/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:45:46 by sbalk             #+#    #+#             */
/*   Updated: 2023/08/07 14:24:26 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**read_input(int fd)
{
	char	**moves;
	char	*valid_input[15];

	*valid_input = ["sa\n", "sb\n"]
	
}

int main(int argc, char *argv)
{
	t_pslist	*a;
	t_pslist	*b;
	char		**moves;

	argc--;
	argv++;
	error_check(argv, argc);
	create_stack(&a, argv, argc);
	
}