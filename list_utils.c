/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:52:36 by sbalk             #+#    #+#             */
/*   Updated: 2023/06/20 17:58:06 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*free_list(t_node *head)
{
	t_node	*next_node;
	t_node	*cur_node;

	next_node = head;
	while (next_node != NULL)
	{
		cur_node = next_node;
		next_node = cur_node->next;
		free(cur_node);
	}
	return (NULL);
}

t_node	*create_node(char *str, int index)
{
	t_node	*new_node;
	new_node = malloc(1 * sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->value = ft_atoi(str);
	new_node->index = index;
	new_node->next = NULL;
	return (new_node);
}

t_node	*get_last_node(t_node *head)
{
	t_node	*tail;

	tail = head;
	while(tail->next != NULL)
		tail = tail->next;
	return (tail);
}