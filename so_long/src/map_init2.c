#include "../include/so_long.h"

int	validmap_cond1(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (-1);
		i++;
	}
	return (1);
}

int	validmap_cond3(char **map)
{
	int	row;
	int	col;
	int	st;
	int	ei;
	int	collect;

	row = -1;
	st = 0;
	ei = 0;
	collect = 0;
	while (map[++row])
	{
		col = -1;
		while (map[row][++col])
		{
			if (map[row][col] == '0' || map[row][col] == '1')
				continue ;
			else if (map[row][col] == 'P')
				st++;
			else if (map[row][col] == 'E')
				ei++;
			else if (map[row][col] == 'C')
				collect++;
			else
				return (0);
		}
	}
	return ((st == 1) && (ei == 1) && (collect >= 1));
}

int	validmap_cond4(char *line)
{
	int	f;
	int	l;
	int	i;

	i = -1;
	f = 0;
	l = 0;
	if (line[0] == '1')
		f = 1;
	while (line[++i] != '\0')
		;
	if ((i > 0) && (line[i - 1] == '1'))
		l = 1;
	return (f && l);
}

int	is_valid_file_path(char *path)
{
	int	len_path;

	len_path = len(path);
	if (len_path < 4)
		return (-1);
	if (ft_strlcmp(path + len_path - 4, ".ber", 4) != 0)
		return (-1);
	return (1);
}

char	**closefd_w_err(int fd, char *t)
{
	close(fd);
	return (map_err(t));
}