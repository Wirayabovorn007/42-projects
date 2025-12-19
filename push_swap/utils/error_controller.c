/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_controller.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:10:51 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/12/19 14:43:00 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_valid_number_format(char *str)
{
	int	i;

	if (!str || !str[0])
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicates_or_overflow(char *argv[])
{
	int		i;
	int		j;
	long	num_i;

	i = 0;
	while (argv[i])
	{
		num_i = ft_atol(argv[i]);
		if (num_i > 2147483647 || num_i < -2147483648)
			return (1);
		j = i + 1;
		while (argv[j])
		{
			if (ft_atol(argv[j]) == num_i)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	has_err(char *argv[])
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!is_valid_number_format(argv[i]))
			return (print_err());
		i++;
	}
	if (has_duplicates_or_overflow(argv))
		return (print_err());
	return (0);
}
