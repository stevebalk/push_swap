/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:12:25 by sbalk             #+#    #+#             */
/*   Updated: 2023/07/20 12:24:21 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	push(t_node **src, t_node **dst)
{
	t_node	*src_head;
	if (*dst == NULL)
		*dst = NULL;
	src_head = *src;
	*src = src_head->next;
	src_head->next = *dst;
	*dst = src_head;
}

void	pa(t_node **a, t_node **b)
{
	push(b, a);
	putstr("pa\n");
}

void	pb(t_node **a, t_node **b)
{
	push(a, b);
	putstr("pb\n");
}
