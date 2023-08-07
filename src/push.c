/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:12:25 by sbalk             #+#    #+#             */
/*   Updated: 2023/08/07 17:57:57 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_pslist **src, t_pslist **dst)
{
	t_pslist	*src_head;

	if (*dst == NULL)
		*dst = NULL;
	src_head = *src;
	*src = src_head->next;
	src_head->next = *dst;
	*dst = src_head;
}

void	pa(t_pslist **a, t_pslist **b, int print)
{
	if (*b)
	{
		push(b, a);
		if (print)
			ft_printf("pa\n");
	}
}

void	pb(t_pslist **a, t_pslist **b, int print)
{
	if (*a)
	{
		push(a, b);
		if (print)
			ft_printf("pb\n");
	}
}
