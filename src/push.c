/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:12:25 by sbalk             #+#    #+#             */
/*   Updated: 2023/06/22 13:52:23 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



static void	push(t_node **src, t_node **dst)
{
	t_node	*src_head;

	src_head = *src;
	*src = src_head->next;
	src_head->next = *dst;
	*dst = src_head;
}

void	pa(t_node **a, t_node **b)
{
	push(a, b);
	putstr("pa\n");
}

void	pb(t_node **a, t_node **b)
{
	push(b, a);
	putstr("pb\n");
}
