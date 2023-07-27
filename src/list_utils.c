/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:52:36 by sbalk             #+#    #+#             */
/*   Updated: 2023/07/27 18:46:05 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

/* Copies a linked list to an array and returns the size */
int	copy_list_to_array(t_node *src, int **dst)
{
	int	list_size;
	int	i;

	list_size = get_list_size(src);
	*dst = malloc(list_size * sizeof(int));
	if (*dst == NULL)
		exit(1);
	i = 0;
	while (src)
	{
		(*dst)[i] = src->index;
		src = src->next;
		i++;
	}

	return list_size;
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