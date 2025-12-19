/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:11:30 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/12/19 14:45:41 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	count_words(char *s, char delimiter)
{
	int	i;
	int	new_word;

	new_word = 0;
	i = 0;
	while (*s)
	{
		if (*s == delimiter)
			new_word = 0;
		else
		{
			if (!new_word)
			{
				new_word = 1;
				i++;
			}
		}
		s++;
	}
	return (i);
}

char	*word_dup(char *str, int len)
{
	int		i;
	char	*dup;

	dup = (char *)malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

void	free_arr(char **arr, int i)
{
	while (i > 0)
		free(arr[--i]);
	free(arr);
}

void	skip_and_count_len(char **s, int *len, char c, int op)
{
	if (op == 1)
	{
		while (**s == c)
			(*s)++;
	}
	else
	{
		while (**s && **s != c)
		{
			(*s)++;
			(*len)++;
		}
	}
}

char	**split_num(char *s, char c)
{
	char		**arr;
	char		*temp;
	int			i;
	int			words;
	int			len;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	arr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	i = -1;
	while (++i < words)
	{
		len = 0;
		skip_and_count_len(&s, &len, c, 1);
		temp = s;
		skip_and_count_len(&s, &len, c, 2);
		arr[i] = word_dup(temp, len);
		if (!arr[i])
			return (free_arr(arr, i), NULL);
	}
	arr[i] = NULL;
	return (arr);
}
