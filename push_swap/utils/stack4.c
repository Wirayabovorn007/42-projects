/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:56:20 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/12/19 14:57:01 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*get_min(t_stack *stack)
{
	long	min;
	t_stack	*minnode;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	minnode = NULL;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			minnode = stack;
		}
		stack = stack->next;
	}
	return (minnode);
}

void	update_index(t_stack *stack)
{
	int	i;
	int	median;

	if (!stack)
		return ;
	i = 0;
	median = len_stack(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->is_above_median = 1;
		else
			stack->is_above_median = 0;
		stack = stack->next;
		i++;
	}
}

void	set_target_a(t_stack *a, t_stack *b)
{
	t_stack	*curr_b;
	t_stack	*target;
	long	bestmatch;

	while (a)
	{
		bestmatch = LONG_MIN;
		curr_b = b;
		target = NULL;
		while (curr_b)
		{
			if (curr_b->value < a->value && curr_b->value > bestmatch)
			{
				bestmatch = curr_b->value;
				target = curr_b;
			}
			curr_b = curr_b->next;
		}
		if (bestmatch == LONG_MIN)
			a->target = get_max(b);
		else
			a->target = target;
		a = a->next;
	}
}

void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack	*curr_a;
	t_stack	*target;
	long	bestmatch;

	while (b)
	{
		bestmatch = LONG_MAX;
		curr_a = a;
		target = NULL;
		while (curr_a)
		{
			if (curr_a->value > b->value && curr_a->value < bestmatch)
			{
				bestmatch = curr_a->value;
				target = curr_a;
			}
			curr_a = curr_a->next;
		}
		if (bestmatch == LONG_MAX)
			b->target = get_min(a);
		else
			b->target = target;
		b = b->next;
	}
}
