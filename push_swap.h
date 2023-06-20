/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:42:58 by sbalk             #+#    #+#             */
/*   Updated: 2023/06/20 17:59:25 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

typedef struct s_node
{
	int				value;
	ssize_t			index;
	struct s_node	*next;
}	t_node;

int		is_digit(char ch);
int 	is_whitespace(char ch);
void	putstr(char	*str);
int		is_correct_input(char **str, int size);
ssize_t	ft_atoi(const char *str);

/* List functions */
t_node	*free_list(t_node *head);
t_node	*create_node(char *str, int index);
t_node	*get_last_node(t_node *head);

/* Push swap functions */