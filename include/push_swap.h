/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:42:58 by sbalk             #+#    #+#             */
/*   Updated: 2023/06/21 12:29:47 by sbalk            ###   ########.fr       */
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

/* Utility */

int		is_digit(char ch);
void	putstr(char	*str);
ssize_t	ft_atoi(const char *str);
void	debug_print_stack(t_node *stack, char *name); // DELETE LATER!!!

/* Error handling */

void	input_check(char **str, int size);
void	is_stack_unsorted(t_node *head);

/* List functions */

t_node	*free_list(t_node *head);
t_node	*create_node(char *str, int index);
t_node	*get_last_node(t_node *head);
t_node	*create_stack(int size, char **strings);

/* Push swap functions */

void	pa(t_node *a, t_node *b);
void	pb(t_node *a, t_node *b);