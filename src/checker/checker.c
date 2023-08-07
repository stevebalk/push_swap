/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:59:41 by sbalk             #+#    #+#             */
/*   Updated: 2023/08/07 16:04:24 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "printf.h"
#include "get_next_line.h"
#include "checker.h"

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

static void	call_instruction(char *op, t_pslist **a, t_pslist **b)
{
	if (ft_streq(op, "sa"))
		sa(a);
	else if (ft_streq(op, "sb"))
		sb(b);
	else if (ft_streq(op, "ss"))
		ss(a, b);
	else if (ft_streq(op, "pa"))
		pa(a, b);
	else if (ft_streq(op, "pb"))
		pb(a, b);
	else if (ft_streq(op, "ra"))
		ra(a);
	else if (ft_streq(op, "rb"))
		rb(b);
	else if (ft_streq(op, "rr"))
		rr(a, b);
	else if (ft_streq(op, "rra"))
		rra(a);
	else if (ft_streq(op, "rrb"))
		rrb(b);
	else if (ft_streq(op, "rrr"))
		rrr(a, b);
}

static int	sort_stack(t_pslist **a, t_pslist **b)
{
	char *line;

	line = get_next_line(stdin);
	while (line)
	{
		if (is_valid_instruction(line))
			call_instruction(line);
		else
		{
			free(line);
			error_free(a, b, NULL, NULL);
		}
		free(line);
		line = get_next_line(stdin);
	}
}

void	check_stacks(&a, &b)
{
	if (b != NULL)
	{
		ft_printf("KO\n");
		return ;
	}
	if (is_list_n_sorted(a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int main(int argc, char **argv)
{
	t_pslist	*a;
	t_pslist	*b;
	int			is_correct_input;

	argc--;
	argv++;
	error_check(argv, argc);
	create_stack(&a, argv, argc);
	read_input(&a, &b);
	check_stacks(&a, &b);
	ps_free_list(&a);
	ps_free_list(&b);
}
