/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:11:26 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/12/19 14:36:31 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	check_input(int *must_free_args, int argc,
	char *argv[], char ***args_to_process)
{
	*must_free_args = 0;
	if (argc == 2 && can_split(argv[1]))
	{
		*args_to_process = split_num(argv[1], ' ');
		*must_free_args = 1;
	}
	else if (argc > 2 && can_join_split(argv + 1))
	{
		*args_to_process = join_n_split(argv);
		*must_free_args = 1;
	}
	else
	{
		*args_to_process = argv + 1;
		*must_free_args = 0;
	}
}

int	push_swap(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	char	**args_to_process;
	int		must_free_args;	

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (!argv[1][0])
		return (print_err());
	check_input(&must_free_args, argc, argv, &args_to_process);
	if (has_err(args_to_process))
	{
		if (must_free_args)
			free_split_array(args_to_process);
		return (1);
	}
	init_stack(&a, args_to_process);
	if (must_free_args)
		free_split_array(args_to_process);
	if (!sorted(a))
		sort_stack(&a, &b);
	free_stack(&a);
	return (0);
}
