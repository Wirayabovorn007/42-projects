
#include "../include/so_long.h"

int len(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

#include <stdio.h> //for testing
void	free_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
	{
		printf("%s\n", arr[i]);
		free(arr[i]);
	}
	free(arr);
}