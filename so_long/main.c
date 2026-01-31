
#include "./include/so_long.h"

int	main(int argc, char *argv[])
{
	char	**map;

	if (argc == 2)
	{
		if (is_validpath(argv[1]) != 1)
		{
			print_err("Invalid file path  or file extension.");
			return EXIT_FAILURE;
		}
		map = read_map(argv[1], argc);
		if (!map)
			return EXIT_FAILURE;
		init_game(map);
	}
	else
	{
		print_err("Invalid number of argument.");
		return EXIT_FAILURE;
	}
}
