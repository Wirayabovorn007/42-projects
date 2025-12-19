/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:51:22 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/12/19 14:56:50 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*get_last_node(t_stack *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

int	len_stack(t_stack *a)
{
	int	i;

	if (!a)
		return (0);
	i = 0;
	while (a)
	{
		a = a->next;
		i++;
	}
	return (i);
}

void	append(t_stack **st, int val)
{
	t_stack	*node;
	t_stack	*last_node;

	if (!st)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->target = NULL;
	node->value = val;
	node->index = 0;
	node->is_cheapest = 0;
	node->is_above_median = 0;
	if (!(*st))
	{
		*st = node;
		node->prev = NULL;
	}
	else
	{
		last_node = get_last_node(*st);
		last_node->next = node;
		node->prev = last_node;
	}
}

int	init_stack(t_stack **a, char *argv[])
{
	int		i;

	i = 0;
	while (argv[i])
	{
		append(a, (int)ft_atol(argv[i]));
		i++;
	}
	return (0);
}

t_stack	*get_max(t_stack *stack)
{
	long	max;
	t_stack	*maxnode;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	maxnode = NULL;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			maxnode = stack;
		}
		stack = stack->next;
	}
	return (maxnode);
}
