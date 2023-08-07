/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:52:36 by sbalk             #+#    #+#             */
/*   Updated: 2023/08/07 16:02:44 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_free_list(t_pslist **head)
{
	t_pslist	*next_pslist;

	while (*head != NULL)
	{
		next_pslist = (*head)->next;
		free(*head);
		*head = next_pslist;
	}
	*head = NULL;
}

t_pslist	*create_node(int value)
{
	t_pslist	*new_node;

	new_node = malloc(1 * sizeof(t_pslist));
	if (new_node == NULL)
		return (NULL);
	new_node->value = value;
	new_node->index = 0;
	new_node->next = NULL;
	return (new_node);
}

int	get_list_size(t_pslist *stack)
{
	int		size;
	t_pslist	*cur_node;

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
int	is_list_n_sorted(t_pslist **stack, int len, int dir)
{
	t_pslist	*cur_node;

	cur_node = *stack;
	if (dir == 1)
	{
		while (cur_node && cur_node->next && len)
		{
			if (cur_node->index > cur_node->next->index)
				return (0);
			len--;
			cur_node = cur_node->next;
		}
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



// void	debug_print_stack(t_pslist *stack, char *name)
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