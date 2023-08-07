/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:35:14 by sbalk             #+#    #+#             */
/*   Updated: 2023/08/07 18:35:44 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Rotates the stack to it's final positon with the
least amount of moves */
static void	last_rotate(t_pslist **a)
{
	t_pslist	*cur_node;
	int			first_index_pos;

	cur_node = *a;
	first_index_pos = 0;
	while (cur_node)
	{
		if (cur_node->index == 0)
			break ;
		first_index_pos++;
		cur_node = cur_node->next;
	}
	if (first_index_pos < 3)
		while (first_index_pos--)
			ra(a, 1);
	else if (first_index_pos != 0)
	{
		while (5 - first_index_pos)
		{
			rra(a, 1);
			first_index_pos++;
		}
	}
}

/* Pushes the the top node of stack b to it's final
position with the least amount of moves */
static void	smart_insert(t_pslist **a, t_pslist **b)
{
	int	next_pos;
	int	i;

	i = 0;
	while (*b)
	{
		if ((*b)->index < 4)
			next_pos = get_next_pos(a, (*b)->index + 1);
		else
			next_pos = get_next_pos(a, 0);
		while (i++ < ft_abs(next_pos))
		{
			if (next_pos < 0)
				rra(a, 1);
			else
				ra(a, 1);
		}
		i = 0;
		pa(a, b, 1);
	}
}

void	sort_three(t_pslist **a)
{
	int	one;
	int	two;
	int	three;

	if (is_list_n_sorted(a, 3, 1))
		return ;
	one = (*a)->index;
	two = (*a)->next->index;
	three = (*a)->next->next->index;
	if (two < one && one < three)
		sa(a, 1);
	else if (three < two && two < one)
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if (two < three && three < one)
		ra(a, 1);
	else if (one < three && three < two)
	{
		sa(a, 1);
		ra(a, 1);
	}
	else
		rra(a, 1);
}

/* Inserts the last two nodes from stack b to
theit final positon in stack a */
void	insert_two(t_pslist **a, t_pslist **b)
{
	if ((*b)->index < (*b)->next->index)
		sb(b, 1);
	smart_insert(a, b);
}

void	sort_five(t_pslist **a, t_pslist **b)
{
	pb(a, b, 1);
	pb(a, b, 1);
	sort_three(a);
	insert_two(a, b);
	last_rotate(a);
}
