/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:43:01 by sbalk             #+#    #+#             */
/*   Updated: 2023/06/20 17:53:22 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"
// #include "error_handling.c"
// #include "utils.c"

t_node	*create_stack(int size, char **strings)
{
	t_node	*head_node;
	t_node	*cur_node;
	t_node	*new_node;
	int		i;

	i = 1;
	head_node = create_node(strings[0], 0);
	if (head_node == NULL)
		exit (1);
	cur_node = head_node;
	while (i < size - 1)
	{
		new_node = create_node(strings[i], i);
		if (new_node == NULL)
		{
			free_list(head_node);
			exit (1);
		}
		cur_node->next = new_node;
		cur_node = new_node;
		i++;
	}
	return (head_node);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	// ssize_t *b;

	argc--;
	argv++;
	input_check(argv, argc);
	a = create_stack(argc, argv);
	a = free_list(a);
	return (0);
}
