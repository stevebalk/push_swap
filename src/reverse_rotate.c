/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:49:28 by sbalk             #+#    #+#             */
/*   Updated: 2023/07/20 15:16:56 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_node	*get_second_last(t_node *node)
{
	while (node->next->next != NULL)
		node = node->next;
	return (node);
}

void	reverse_rotate(t_node **head)
{
	t_node	*tail;
	t_node	*second_last;

	second_last = get_second_last(*head);
	tail = second_last->next;
	second_last->next = NULL;
	tail->next = *head;
	*head = tail;
}

void	rra(t_node **a)
{
	if ((*a)->next != NULL)
	{
		reverse_rotate(a);
		putstr("rra\n");
	} 
}

void	rrb(t_node **b)
{
	if ((*b)->next != NULL)
	{
		reverse_rotate(b);
		putstr("rrb\n");
	}
}

void	rrr(t_node **a, t_node **b)
{
	rra(a);
	rrb(b);
}
