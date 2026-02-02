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
	line = get_next_line(fd);
	while (line != NULL)
	{
		lc++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (lc);
}

char	**map_err(char *type)
{
	write(2, "Error\n", 6);
	if (type)
	{
		write(2, "Type: ", 6);
		write(2, type, len(type));
	}
	write(2, "\n", 1);
	return (NULL);
}

char	**map_errwf(char *type, char **arr)
{
	free_arr(arr);
	write(2, "Error\n", 6);
	if (type)
	{
		write(2, "Type: ", 6);
		write(2, type, len(type));
	}
	write(2, "\n", 1);
	return (NULL);
}

char	**validate_map(char **arr, int line_count)
{
	char	**t;
	int		row;
	int		len_fline;

	t = arr;
	if (line_count <= 1 || !t || !t[0])
		return (map_errwf("Map is empty.", arr));
	row = 0;
	len_fline = len(t[row]);
	if ((validmap_cond1(t[0]) != 1)
		|| (validmap_cond1(t[line_count - 1]) != 1)
		|| (validmap_cond3(t) != 1))
		return (map_errwf("Invalid border or components.", arr));
	while (t[row])
	{
		if (len(t[row]) != len_fline)
			return (map_errwf("Invalid line length.", arr));
		if (validmap_cond4(t[row]) != 1)
			return (map_errwf("Invalid side borders.", arr));
		row++;
	}
	if (is_valid_path(arr) == 0)
		return (map_errwf("Map contains invalid path.", arr));
	return (arr);
}

char	**read_map(char *path, int argc)
{
	int		fd;
	int		i;
	int		line_len;
	char	*line;
	char	**line_arr;

	fd = open(path, O_RDONLY);
	if (fd < 0 || get_line_count(path) <= 0 || argc != 2)
		return (map_err("Empty file or open/read error."));
	i = 0;
	line_arr = malloc(sizeof(char *) * (get_line_count(path) + 1));
	if (!line_arr)
		closefd_w_err(fd, "Memory allocation.");
	line = get_next_line(fd);
	while (line != NULL)
	{
		line_len = len(line);
		if (line_len > 0 && line[line_len - 1] == '\n')
			line[line_len - 1] = '\0';
		line_arr[i++] = line;
		line = get_next_line(fd);
	}
	line_arr[i] = NULL;
	close(fd);
	return (validate_map(line_arr, get_line_count(path)));
}
