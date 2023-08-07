/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:14:42 by sbalk             #+#    #+#             */
/*   Updated: 2023/08/07 18:14:21 by sbalk            ###   ########.fr       */
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

void	sa(t_pslist **a, int print)
{
	if ((*a) && (*a)->next)
	{
		swap(a);
		if (print)
			ft_printf("sa\n");
	}
}

void	sb(t_pslist **b, int print)
{
	if ((*b) && (*b)->next)
	{
		swap(b);
		if (print)
			ft_printf("sb\n");
	}
}

void	ss(t_pslist **a, t_pslist **b, int print)
{
	if ((*a)->next && (*b)->next)
	{
		swap(a);
		swap(b);
		if (print)
			ft_printf("ss\n");
	}
}
