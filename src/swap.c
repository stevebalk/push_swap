/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:14:42 by sbalk             #+#    #+#             */
/*   Updated: 2023/07/29 18:50:57 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_node **head)
{
	t_node	*new_head;

	new_head = (*head)->next;
	(*head)->next = (*head)->next->next;
	new_head->next = *head;
	*head = new_head;
}

void	sa(t_node **a)
{
	if ((*a)->next)
	{
		swap(a);
		putstr("sa\n");
	}
}

void	sb(t_node **b)
{
	if ((*b)->next)
	{
		swap(b);
		putstr("sb\n");
	}
}

void	ss(t_node **a, t_node **b)
{
	if ((*a)->next && (*b)->next)
	{
		swap(a);
		swap(b);
		putstr("ss\n");
	}
}
