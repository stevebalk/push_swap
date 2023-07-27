/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:25:29 by sbalk             #+#    #+#             */
/*   Updated: 2023/07/27 12:33:25 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_digit(char ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	return (0);
}

void	putstr(char	*str)
{
	while(*str)
	{
		write(1, str, 1);
		str++;
	}
}

ssize_t	ft_atoi(const char *str)
{
	ssize_t	nb;
	int		sign;

	nb = 0;
	sign = 1;
	while (*str == '\f' || *str == '\n' || *str == '\r'
		|| *str == '\t' || *str == '\v' || *str == ' ')
	{
		str++;
	}
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9' && *str != '\0')
	{
		nb *= 10;
		nb += *str - '0';
		str++;
	}
	return (nb * sign);
}

int	ft_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

/* Checks for n elements if given list is sorted.
dir 1 == Lower to higher, dir -1 higher to lower*/
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
	printf("Sorted!!");
	return (1);
}