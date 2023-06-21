/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:12:25 by sbalk             #+#    #+#             */
/*   Updated: 2023/06/21 12:44:48 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



static void	push(t_node *src, t_node *dst)
{
	t_node *temp;

	temp = src->next;
	src->next = dst;
	dst = src;
	src = temp;
}

void	pa(t_node *a, t_node *b)
{
	push(a, b);
	putstr("pa\n");
}

void	pb(t_node *a, t_node *b)
{
	push(b, a);
	putstr("pb\n");
}
