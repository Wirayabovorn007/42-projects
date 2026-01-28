
#include "../include/so_long.h"

int len(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

int	ft_strlcmp(char *s1, char *s2, int max)
{
	int	i;

	i = 0;
	while ((i < max - 1) && (s1[i] && s2[i]))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

#include <stdio.h> //for testing
void	free_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
	{
		// printf("%s\n", arr[i]);
		free(arr[i]);
	}
	free(arr);
}

void	print_err(char *err)
{
	write(2,"Error\n", 6);
	if (err)
	{
		write(2, "Type: ", 6);
		write(2, err, len(err));
	}
	write(2, "\n", 1);
}