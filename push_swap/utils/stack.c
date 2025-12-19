/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:11:34 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/12/19 14:50:43 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_with_cheap(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		rr(a, b);
	update_index(*a);
	update_index(*b);
}

void	rev_rotate_with_cheap(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		rrr(a, b);
	update_index(*a);
	update_index(*b);
}

void	required_node_to_top(t_stack **stack, t_stack *top, char st)
{
	while (*stack != top)
	{
		if (st == 'a')
		{
			if (top->is_above_median)
				ra(stack);
			else
				rra(stack);
		}
		if (st == 'b')
		{
			if (top->is_above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	move_cheapest_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(*a);
	if (!cheapest)
		return ;
	if (cheapest->is_above_median && cheapest->target->is_above_median)
		rotate_with_cheap(a, b, cheapest);
	else if (!(cheapest->is_above_median)
		&& !(cheapest->target->is_above_median))
		rev_rotate_with_cheap(a, b, cheapest);
	required_node_to_top(a, cheapest, 'a');
	required_node_to_top(b, cheapest->target, 'b');
	pb(a, b);
}

void	move_cheapest_b_to_a(t_stack **a, t_stack **b)
{
	if (!*b)
		return ;
	required_node_to_top(a, (*b)->target, 'a');
	pa(a, b);
}
