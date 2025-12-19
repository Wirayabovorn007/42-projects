/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiraya <wiraya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:46:09 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/12/19 17:49:37 by wiraya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	set_node_cost(t_stack *node, int len_a, int len_b)
{
	int	cost_a;
	int	cost_b;

	cost_a = node->index;
	if (!node->is_above_median)
		cost_a = len_a - node->index;
	cost_b = 0;
	if (node->target)
	{
		cost_b = node->target->index;
		if (!node->target->is_above_median)
			cost_b = len_b - node->target->index;
	}
	if (node->target && (node->is_above_median == node->target->is_above_median))
	{
		if (cost_a > cost_b)
			node->push_cost = cost_a;
		else
			node->push_cost = cost_b;
	}
	else
		node->push_cost = cost_a + cost_b;
}

void	calculate_push_cost_a(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = len_stack(a);
	len_b = len_stack(b);
	while (a)
	{
		set_node_cost(a, len_a, len_b);
		a = a->next;
	}
}

void	update_a(t_stack *a, t_stack *b)
{
	update_index(a);
	update_index(b);
	set_target_a(a, b);
	calculate_push_cost_a(a, b);
	set_is_cheapest(a);
}

void	update_b(t_stack *a, t_stack *b)
{
	update_index(a);
	update_index(b);
	set_target_b(a, b);
}

t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->is_cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
