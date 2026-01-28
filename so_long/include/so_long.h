

# ifndef SO_LONG_H
# define SO_LONG_H

#define BUFFER_SIZE 1024

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../src/get_next_line/get_next_line.h"

char	**read_map(char *path);
char	**map_err(char *type);
void	free_arr(char **arr);
int		len(char *str);

#endif