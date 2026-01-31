#include "../include/so_long.h"

int	get_map_height(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		;
	return (i);
}

void	render_map(char **map, s_game *game)
{
	int	row;
	int	col;
	char	curr_pos;

	row = -1;
	while (map[++row])
	{
		col = -1;
		while (map[row][++col])
		{
			curr_pos = map[row][col];
			if (curr_pos == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, IMG_WALL, game->map_w * IMG_PX, game->map_h * IMG_PX);
			if (curr_pos == '0')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, IMG_MAP, game->map_w * IMG_PX, game->map_h * IMG_PX);
			if (curr_pos == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, IMG_COIN, game->map_w * IMG_PX, game->map_h * IMG_PX);
			if (curr_pos == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, IMG_EXIT, game->map_w * IMG_PX, game->map_h * IMG_PX);
			if (curr_pos == 'P')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, IMG_PLAYER, game->map_w * IMG_PX, game->map_h * IMG_PX);
		}
	}
}

void	err_free(char **arr)
{
	free_arr(arr);
	return ;
}

void	init_game(char **map)
{
	int	w;
	int	h;
	s_game	game;

	game.mlx_ptr = mlx_init();
	if (game.mlx_ptr == NULL)
		return err_free(map);
	game.map_w = len(map[0]);
	game.map_h = get_map_height(map);
	game.win_ptr = mlx_new_window(game.mlx_ptr, game.map_w * IMG_PX, game.map_h * IMG_PX, "so_long");
	if (game.win_ptr == NULL)
		return (err_free(map));
	game.img_player = mlx_xpm_file_to_image(game.mlx_ptr, IMG_PLAYER, &w, &h);
	if (!game.img_player)
		return err_free(map);
	render_map(map, &game);
	free_arr(map);
}

