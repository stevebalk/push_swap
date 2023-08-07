/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:12:25 by sbalk             #+#    #+#             */
/*   Updated: 2023/08/07 14:31:50 by sbalk            ###   ########.fr       */
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

void	pa(t_pslist **a, t_pslist **b)
{
	push(b, a);
	ft_printf("pa\n");
}

void	pb(t_pslist **a, t_pslist **b)
{
	push(a, b);
	ft_printf("pb\n");
}
