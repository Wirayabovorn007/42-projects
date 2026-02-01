#include "../include/so_long.h"

void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

char	**duplicate_map(char **map)
{
	char	**dup;
	int		i;

	i = -1;
	while (map[++i])
		;
	dup = malloc(sizeof(char *) * (i + 1));
	if (!dup)
		return (NULL);
	i = -1;
	while (map[++i])
	{
		dup[i] = ft_strdup(map[i]);
		if (!dup)
		{
			free_arr(dup);
			return NULL;
		}

	}
	dup[i] = NULL;
	return (dup);
}

int	check_path(char **map_dup)
{
	int	i;
	int	j;

	i = 0;
	while (map_dup[i])
	{
		j = 0;
		while (map_dup[i][j])
		{
			if (map_dup[i][j] == 'C' || map_dup[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	get_playerpos(char **map, int *x, int *y)
{
	int	row;
	int	col;

	row = -1;
	while (map[++row])
	{
		col = -1;
		while (map[row][++col])
		{
			if (map[row][col] == 'P')
			{
				*x = col;
				*y = row;
				return ;
			}
		}
	}
}

int	is_valid_path(char **map)
{
	char	**temp_map;
	int		p_x;
	int		p_y;

	temp_map = duplicate_map(map);
	if (!temp_map)
		return (0);
	get_playerpos(map, &p_x, &p_y);
	flood_fill(temp_map, p_x, p_y);
	if (!check_path(temp_map))
	{
		free_arr(temp_map);
		return (0);
	}
	free_arr(temp_map);
	return (1);
}
