/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:46:09 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/12/19 15:33:28 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	calculate_push_cost_a(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;
	int	cost_a;
	int	cost_b;

	len_a = len_stack(a);
	len_b = len_stack(b);
	while (a)
	{
		cost_a = a->index;
		if (!(a->is_above_median))
			cost_a = len_a - a->index;
		cost_b = 0;
		if (a->target)
		{
			cost_b = a->target->index;
			if (!(a->target->is_above_median))
				cost_b = len_b - a->target->index;
		}
		if (a->is_above_median && a->target && a->target->is_above_median)
		{
			if (cost_a > cost_b)
				a->push_cost = cost_a;
			else
				a->push_cost = cost_b;
		}
		else if (!a->is_above_median && a->target
			&& !a->target->is_above_median)
		{
			if (cost_a > cost_b)
				a->push_cost = cost_a;
			else
				a->push_cost = cost_b;
		}
		else
			a->push_cost = cost_a + cost_b;
		a = a->next;
	}
}

void	set_is_cheapest(t_stack	*stack)
{
	long	cheapest_val;
	t_stack	*cheapest_node;
	t_stack	*curr;

	if (!stack)
		return ;
	curr = stack;
	while (curr)
	{
		curr->is_cheapest = 0;
		curr = curr->next;
	}
	cheapest_node = NULL;
	cheapest_val = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_val)
		{
			cheapest_val = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	if (cheapest_node)
		cheapest_node->is_cheapest = 1;
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
