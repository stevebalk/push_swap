/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:49:28 by sbalk             #+#    #+#             */
/*   Updated: 2023/08/07 14:31:30 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_pslist	*get_second_last(t_pslist *node)
{
	while (node->next->next != NULL)
		node = node->next;
	return (node);
}

void	reverse_rotate(t_pslist **head)
{
	t_pslist	*tail;
	t_pslist	*second_last;

	if (*head && (*head)->next)
	{
		second_last = get_second_last(*head);
		tail = second_last->next;
		second_last->next = NULL;
		tail->next = *head;
		*head = tail;
	}
}

void	rra(t_pslist **a)
{
	if ((*a)->next != NULL)
	{
		reverse_rotate(a);
		ft_printf("rra\n");
	}
}

void	rrb(t_pslist **b)
{
	if ((*b)->next != NULL)
	{
		reverse_rotate(b);
		ft_printf("rrb\n");
	}
}

void	rrr(t_pslist **a, t_pslist **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
