
#include "./include/so_long.h"

int	main(int argc, char *argv[])
{
	char	**map;

	map = read_map(argv[1], argc);
	if (!map)
	{
		free_arr(map);
		return EXIT_FAILURE;
	}

	free_arr(map);
}
