/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:12:05 by sbalk             #+#    #+#             */
/*   Updated: 2023/06/21 14:32:42 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_stack_unsorted(t_node *head)
{
	t_node	*cur_node;

	cur_node = head;
	while (cur_node->next != NULL)
	{
		if (cur_node->value > cur_node->next->value)
			return ;
		cur_node = cur_node->next;
	}
	free_list(head);
	exit (0);
}

static int	is_number(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!is_digit(*str))
			return (0);
		str++;
	}
	return (1);
}

static int is_int(char *str)
{
	ssize_t	nbr;

	if (!is_number(str))
		return (0);
	nbr = ft_atoi(str);
	if (nbr < INT_MIN || nbr > INT_MAX)
		return (0);
	return (1);
}

void	input_check(char **str, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (*str == NULL || !is_int(*str))
		{
			putstr("Error\n");
			exit (1);
		}
		str++;
		i++;
	}
	if (size <= 1)
		exit (0);
}

