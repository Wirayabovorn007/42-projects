
#include "./include/so_long.h"

int	main(int argc, char *argv[])
{
	char	**map;

	if (is_validpath(argv[1]) != 1)
	{
		print_err("Invalid file path  or file extension.");
		return EXIT_FAILURE;
	}
	map = read_map(argv[1], argc);
	if (!map)
	{
		free_arr(map);
		return EXIT_FAILURE;
	}

	free_arr(map);
}
