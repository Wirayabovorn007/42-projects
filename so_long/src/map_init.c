#include "../include/so_long.h"

int	get_line_count(char *path)
{
	int		lc;
	int		fd;
	char	*line;

	lc = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	while ((line = get_next_line(fd)) != NULL)
	{
		lc++;
		free(line);
	}
	close(fd);
	return (lc);
}

char	**map_err(char *type)
{
	write(2,"Error\n", 6);
	if (type)
	{
		write(2, "Type: ", 6);
		write(2, type, len(type));
	}
	write(2, "\n", 1);
	return NULL;
}
char	**map_errwf(char *type, char **arr)
{
	free_arr(arr);
	write(2,"Error\n", 6);
	if (type)
	{
		write(2, "Type: ", 6);
		write(2, type, len(type));
	}
	write(2, "\n", 1);
	return NULL;
}

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

char **validate_map(char **arr, int line_count)
{
	char	**t;
	int		row;
	int		len_fline;

	t = arr;
	if (line_count <= 1 || !t || !t[0])
	{
		free_arr(arr);
		return map_errwf("Map is empty.", arr);
	}
	row = 0;
	len_fline = len(t[row]);
	if ((validmap_cond1(t[0]) != 1) || // the first line must include only wall (1)
			(validmap_cond1(t[line_count - 1]) != 1) // the last line must include only wall (1)
				|| (validmap_cond3(t) != 1)) // map must contain 1 == exit, 1 == starting point, at least 1 >= collectible
		return map_errwf("Invalid border or components.", arr);
	while (t[row])
	{
		if (len(t[row]) != len_fline) // all lines must have the same length
			return (map_errwf("Invalid line length.", arr));
		if (validmap_cond4(t[row]) != 1) // first and last char of every line must be 1
			return (map_errwf("Invalid side borders.", arr));
		row++;
	}
	if (is_valid_path(arr) == 0)
		return map_errwf("Map contains invalid path.", arr);
	return (arr);
}

char	**read_map(char *path, int argc)
{
	int		fd;
	int		i;
	int		line_len;
	int		line_count;
	char	*line;
	char	**line_arr;

	fd = open(path, O_RDONLY);
	line_count = get_line_count(path);
	if (fd < 0 || line_count <= 0 || argc != 2)
		return (map_err("Empty file or open/read error, check your file path."));
	i = 0;
	line_arr = malloc(sizeof(char *) * (line_count + 1));
	if (!line_arr)
	{
		close(fd);
		return (map_err("Memory allocation."));
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		line_len = len(line);
		if (line_len > 0 && line[line_len - 1] == '\n')
			line[line_len - 1] = '\0';
		line_arr[i++] = line;
	}
	line_arr[i] = NULL;
	close(fd);
	return (validate_map(line_arr, line_count));
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
