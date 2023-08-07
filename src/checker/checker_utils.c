/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:55:51 by sbalk             #+#    #+#             */
/*   Updated: 2023/08/07 15:59:20 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_list_sorted(t_pslist **stack)
{
	t_pslist	*cur_node;

	cur_node = *stack;
	while (cur_node && cur_node->next)
	{
		if (cur_node->index > cur_node->next->index)
			return (0);
		cur_node = cur_node->next;
	}
	return (1);
}
