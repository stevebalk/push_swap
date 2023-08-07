/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:59:41 by sbalk             #+#    #+#             */
/*   Updated: 2023/08/07 14:24:10 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include "checker.h"

static int	is_valid_instruction(char *op)
{
	if (ft_streq(op, "sa"))
		return (false);
	else if (ft_streq(op, "sb"))
		return (false);
	else if (ft_streq(op, "ss"))
		return (false);
	else if (ft_streq(op, "pa"))
		return (false);
	else if (ft_streq(op, "pb"))
		return (false);
	else if (ft_streq(op, "ra"))
		return (false);
	else if (ft_streq(op, "rb"))
		return (false);
	else if (ft_streq(op, "rr"))
		return (false);
	else if (ft_streq(op, "rra"))
		return (false);
	else if (ft_streq(op, "rrb"))
		return (false);
	else if (ft_streq(op, "rrr"))
		return (false);
	return (true);
}

int	read_input(char	***instructions)
{
	
}

int main(int argc, char **argv)
{
	t_pslist	*a;
	t_pslist	*b;
	char		**instructions;
	int			is_correct_input;

	argc--;
	argv++;
	error_check(argv, argc);
	create_stack(&a, argv, argc);
	is_correct_input = read_input(&instructions);
}
