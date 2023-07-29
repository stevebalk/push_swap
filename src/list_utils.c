/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:52:36 by sbalk             #+#    #+#             */
/*   Updated: 2023/07/29 15:44:02 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_node **head)
{
	t_node	*next_node;

	while (*head != NULL)
	{
		next_node = (*head)->next;
		free(*head);
		*head = next_node;
	}
	*head = NULL;
}

t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = malloc(1 * sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->value = value;
	new_node->index = 0;
	new_node->next = NULL;
	return (new_node);
}

int	get_list_size(t_node *stack)
{
	int	size;
	t_node	*cur_node;

	size = 0;
	cur_node = stack;
	while (cur_node != NULL)
	{
		size++;
		cur_node = cur_node->next;
	}
	return (size);
}

/* Checks if list is sorted for n elements.
dir 1 == low to high, dir -1 high to low */
int	is_list_n_sorted(t_node **stack, int len, int dir)
{
	t_node	*cur_node;

	cur_node = *stack;
	if (dir == 1)
		while (cur_node && cur_node->next && len)
		{
			if (cur_node->index > cur_node->next->index)
				return (0);
			len--;
			cur_node = cur_node->next;
		}
	else if (dir == -1)
	{
		while (cur_node && cur_node->next && len)
		{
			if (cur_node->index < cur_node->next->index)
				return (0);
			len--;
			cur_node = cur_node->next;
		}
	}
	return (1);
}

// void	debug_print_stack(t_node *stack, char *name)
// {
// 	printf("-----------\n");
// 	printf("Stack %s\n", name);
// 	while (stack != NULL)
// 	{
// 		printf("%i, index: %i\n", stack->value, stack->index);
// 		stack = stack->next;
// 	}
// 	printf("-----------\n");
// }