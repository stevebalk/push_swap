/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:59:41 by sbalk             #+#    #+#             */
/*   Updated: 2023/08/07 18:34:53 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "printf.h"
#include "get_next_line.h"
#include "checker.h"

static int	is_valid_instruction(char *op)
{
	if (ft_streq(op, "sa\n"))
		return (1);
	else if (ft_streq(op, "sb\n"))
		return (1);
	else if (ft_streq(op, "ss\n"))
		return (1);
	else if (ft_streq(op, "pa\n"))
		return (1);
	else if (ft_streq(op, "pb\n"))
		return (1);
	else if (ft_streq(op, "ra\n"))
		return (1);
	else if (ft_streq(op, "rb\n"))
		return (1);
	else if (ft_streq(op, "rr\n"))
		return (1);
	else if (ft_streq(op, "rra\n"))
		return (1);
	else if (ft_streq(op, "rrb\n"))
		return (1);
	else if (ft_streq(op, "rrr\n"))
		return (1);
	return (0);
}

static void	call_instruction(char *op, t_pslist **a, t_pslist **b)
{
	if (ft_streq(op, "sa\n"))
		sa(a, 0);
	else if (ft_streq(op, "sb\n"))
		sb(b, 0);
	else if (ft_streq(op, "ss\n"))
		ss(a, b, 0);
	else if (ft_streq(op, "pa\n"))
		pa(a, b, 0);
	else if (ft_streq(op, "pb\n"))
		pb(a, b, 0);
	else if (ft_streq(op, "ra\n"))
		ra(a, 0);
	else if (ft_streq(op, "rb\n"))
		rb(b, 0);
	else if (ft_streq(op, "rr\n"))
		rr(a, b, 0);
	else if (ft_streq(op, "rra\n"))
		rra(a, 0);
	else if (ft_streq(op, "rrb\n"))
		rrb(b, 0);
	else if (ft_streq(op, "rrr\n"))
		rrr(a, b, 0);
}

static void	sort_stack(t_pslist **a, t_pslist **b)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (is_valid_instruction(line))
			call_instruction(line, a, b);
		else
		{
			free(line);
			error_free(a, b, NULL, NULL);
		}
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
}

static void	check_stacks(t_pslist **a, t_pslist **b)
{
	if (*b != NULL)
	{
		ft_printf("KO\n");
		return ;
	}
	if (is_list_sorted(a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char **argv)
{
	t_pslist	*a;
	t_pslist	*b;

	a = NULL;
	b = NULL;
	argc--;
	argv++;
	error_check(argv, argc);
	create_stack(&a, argv, argc);
	sort_stack(&a, &b);
	check_stacks(&a, &b);
	ps_free_list(&a);
	ps_free_list(&b);
}
