/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:25:29 by sbalk             #+#    #+#             */
/*   Updated: 2023/07/26 17:51:38 by sbalk            ###   ########.fr       */
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
