
#include "./include/so_long.h"

int	main(void)
{
	char	**map;

	map = read_map("./maps/map.ber");
	if (!map)
	{
		free_arr(map);
		return EXIT_FAILURE;
	}

	free_arr(map);
}
