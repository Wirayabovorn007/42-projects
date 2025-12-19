/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:10:56 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/12/19 14:36:31 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_stack(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*curr;

	if (!a)
		return ;
	curr = *a;
	while (curr)
	{
		tmp = curr->next;
		curr->value = 0;
		free(curr);
		curr = tmp;
	}
	*a = NULL;
}
