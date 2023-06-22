/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:14:42 by sbalk             #+#    #+#             */
/*   Updated: 2023/06/22 16:24:59 by sbalk            ###   ########.fr       */
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
	swap(a);
	putstr("sa\n");
}

void	sb(t_node **b)
{
	swap(b);
	putstr("sb\n");
}

void	ss(t_node **a, t_node **b)
{
	sa(a);
	sb(b);
}