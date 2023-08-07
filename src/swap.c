/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:14:42 by sbalk             #+#    #+#             */
/*   Updated: 2023/08/07 14:30:46 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_pslist **head)
{
	t_pslist	*new_head;

	new_head = (*head)->next;
	(*head)->next = (*head)->next->next;
	new_head->next = *head;
	*head = new_head;
}

void	sa(t_pslist **a)
{
	if ((*a)->next)
	{
		swap(a);
		ft_printf("sa\n");
	}
}

void	sb(t_pslist **b)
{
	if ((*b)->next)
	{
		swap(b);
		ft_printf("sb\n");
	}
}

void	ss(t_pslist **a, t_pslist **b)
{
	if ((*a)->next && (*b)->next)
	{
		swap(a);
		swap(b);
		ft_printf("ss\n");
	}
}
