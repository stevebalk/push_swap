/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:06:33 by sbalk             #+#    #+#             */
/*   Updated: 2023/08/07 14:30:57 by sbalk            ###   ########.fr       */
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

void	ra(t_pslist **stack)
{
	if ((*stack)->next)
	{
		rotate(stack);
		ft_printf("ra\n");
	}
}

void	rb(t_pslist **stack)
{
	if ((*stack)->next)
	{
		rotate(stack);
		ft_printf("rb\n");
	}
}

void	rr(t_pslist **a, t_pslist **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
