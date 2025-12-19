/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:10:26 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/12/19 14:39:32 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_stack **src, t_stack **dst)
{
	t_stack	*to_be_pushed;

	if (!*src)
		return ;
	to_be_pushed = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	to_be_pushed->prev = NULL;
	if (!*dst)
	{
		*dst = to_be_pushed;
		to_be_pushed->next = NULL;
	}
	else
	{
		to_be_pushed->next = *dst;
		to_be_pushed->next->prev = to_be_pushed;
		*dst = to_be_pushed;
	}
}

void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
