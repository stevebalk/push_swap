/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_list_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:42:12 by sbalk             #+#    #+#             */
/*   Updated: 2023/07/29 15:42:32 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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