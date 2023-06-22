/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:06:33 by sbalk             #+#    #+#             */
/*   Updated: 2023/06/22 14:49:21 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node **head)
{
	t_node	*new_head;
	t_node	*tail;

	new_head = (*head)->next;
	tail = get_last_node(*head);
	(*head)->next = NULL;
	tail->next = *head;
	*head = new_head;
}

void	ra(t_node **stack)
{
	rotate(stack);
	putstr("ra\n");
}

void	rb(t_node **stack)
{
	rotate(stack);
	putstr("rb\n");
}

void	rr(t_node **a, t_node **b)
{
	ra(a);
	rb(b);
}