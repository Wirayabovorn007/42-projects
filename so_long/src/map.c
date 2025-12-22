
#include "../include/so_long.h"

int	validate_line(char *line, int *c, int *e, int *p, int t_or_bt)
{
	int	i;

	i = -1;
	if (line[0] != '1' || (line[ft_strlen(line) - 1] != '1'))
		return (0);
	if (t_or_bt)
		while (line[++i])
			if (line[i] != '1')
				return (0);
	i = -1;
	while (line[++i])
	{
		if (line[i] == 'C')
			*c++;
		if (line[i] == 'E')
			*e++;
		if (line[i] == 'P')
			*p++;
	}
	return (1);
}

int	read_map(const char *filename)
{
	int	c;
	int	e;
	int	p;
	int	fd;
	char *line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (print_err());
	c = 0;
	p = 0;
	e = 0;
	line = get_next_line(fd); //check first line
	if (line)
	{
		validate_line(line, &c, &p, &e, 1);
		free(line);
	}
	while ((line = get_next_line(fd)) != NULL) //check lines
	{
		validate_line(line, &c, &p, &e, 1);
		free(line);
	}

	close(fd);
	return 0;
}
