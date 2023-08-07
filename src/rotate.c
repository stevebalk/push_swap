/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:06:33 by sbalk             #+#    #+#             */
/*   Updated: 2023/08/07 18:35:53 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_pslist	*get_last_pslist(t_pslist *node)
{
	if (node == NULL)
		return (NULL);
	while (node->next != NULL)
		node = node->next;
	return (node);
}

void	rotate(t_pslist **head)
{
	t_pslist	*new_head;
	t_pslist	*tail;

	if (*head && (*head)->next)
	{
		new_head = (*head)->next;
		tail = get_last_pslist(*head);
		(*head)->next = NULL;
		tail->next = *head;
		*head = new_head;
	}
}

void	ra(t_pslist **stack, int print)
{
	if (*stack && (*stack)->next)
	{
		rotate(stack);
		if (print)
			ft_printf("ra\n");
	}
}

void	rb(t_pslist **stack, int print)
{
	if (*stack && (*stack)->next)
	{
		rotate(stack);
		if (print)
			ft_printf("rb\n");
	}
}

void	rr(t_pslist **a, t_pslist **b, int print)
{
	rotate(a);
	rotate(b);
	if (print)
		ft_printf("rr\n");
}
