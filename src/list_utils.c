/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:52:36 by sbalk             #+#    #+#             */
/*   Updated: 2023/07/10 15:32:38 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_list(t_node **head)
{
	t_node	*cur_node;

	while (*head != NULL)
	{
		cur_node = *head;
		*head = cur_node->next;
		free(cur_node);
	}
	*head = NULL;
}

t_node	*create_node(int value, int *sorted_array, int size)
{
	int i;

	i = 0;
	t_node	*new_node;

	new_node = malloc(1 * sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->value = value;
	while (i < size)
	{
		if (sorted_array[i] == new_node->value)
		{
			new_node->index = i;
			break;
		}
		i++;
	}
	new_node->next = NULL;
	return (new_node);
}

t_node	*create_stack(int size, int *nums, int *sorted_nums)
{
	t_node	*head_node;
	t_node	*cur_node;
	t_node	*new_node;
	int		i;

	i = 1;
	head_node = create_node(nums[0], sorted_nums, size);
	if (head_node == NULL)
		exit (1);
	cur_node = head_node;
	while (i < size)
	{
		new_node = create_node(nums[i], sorted_nums, size);
		if (new_node == NULL)
		{
			free_list(&head_node);
			exit (1);
		}
		cur_node->next = new_node;
		cur_node = new_node;
		i++;
	}
	return (head_node);
}

t_node	*get_last_node(t_node *node)
{
	if (node == NULL)
		return (NULL);
	while (node->next != NULL)
		node = node->next;
	return (node);
}

void	debug_print_stack(t_node *stack, char *name)
{
	printf("-----------\n");
	printf("Stack %s\n", name);
	while (stack != NULL)
	{
		printf("%i, index: %i\n", stack->value, stack->index);
		stack = stack->next;
	}
	printf("-----------\n");
}