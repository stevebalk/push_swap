/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:45:26 by sbalk             #+#    #+#             */
/*   Updated: 2023/08/07 14:21:26 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	putstr(char	*str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	str_arr_len(char **arr)
{
	int	size;

	size = 0;
	while (*arr)
	{
		arr++;
		size++;
	}
	return size;
}
