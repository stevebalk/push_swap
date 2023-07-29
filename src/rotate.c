/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:06:33 by sbalk             #+#    #+#             */
/*   Updated: 2023/07/29 15:44:19 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*get_last_node(t_node *node)
{
	if (node == NULL)
		return (NULL);
	while (node->next != NULL)
		node = node->next;
	return (node);
}

void	rotate(t_node **head)
{
	t_node	*new_head;
	t_node	*tail;

	if (*head && (*head)->next)
	{
		new_head = (*head)->next;
		tail = get_last_node(*head);
		(*head)->next = NULL;
		tail->next = *head;
		*head = new_head;
	}
}

void	ra(t_node **stack)
{
	if ((*stack)->next)
	{
		rotate(stack);
		putstr("ra\n");
	}
}

void	rb(t_node **stack)
{
	if ((*stack)->next)
	{
		rotate(stack);
		putstr("rb\n");
	}
}

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	putstr("rr\n");
}