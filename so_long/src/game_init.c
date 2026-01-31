#include "../include/so_long.h"

int	get_map_height(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		;
	return (i);
}

void	render_map(s_game *game)
{
	int	row;
	int	col;
	char	curr_pos;

	row = -1;
	while (game->map[++row])
	{
		col = -1;
		while (game->map[row][++col])
		{
			curr_pos = game->map[row][col];
			if (curr_pos == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->wall_img, col * IMG_PX, row * IMG_PX);
			if (curr_pos == '0')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->floor_img, col * IMG_PX, row * IMG_PX);
			if (curr_pos == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->coin_img, col * IMG_PX, row * IMG_PX);
			if (curr_pos == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->exit_img, col * IMG_PX, row * IMG_PX);
			if (curr_pos == 'P')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player_img, col * IMG_PX, row * IMG_PX);
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
	game.map = map;
	game.map_w = len(game.map[0]);
	game.map_h = get_map_height(game.map);
	game.win_ptr = mlx_new_window(game.mlx_ptr, game.map_w * IMG_PX, game.map_h * IMG_PX, "so_long");
	if (game.win_ptr == NULL)
		return (err_free(game.map));
	game.wall_img = mlx_xpm_file_to_image(game.mlx_ptr, "assets/wall.xpm", &w, &h);
	game.floor_img = mlx_xpm_file_to_image(game.mlx_ptr, "assets/map_bg.xpm", &w, &h);
	game.coin_img = mlx_xpm_file_to_image(game.mlx_ptr, "assets/collectible.xpm", &w, &h);
	game.player_img = mlx_xpm_file_to_image(game.mlx_ptr, "assets/player-d-1.xpm", &w, &h);
	game.exit_img = mlx_xpm_file_to_image(game.mlx_ptr, "assets/exit.xpm", &w, &h);
	if (!game.wall_img || !game.floor_img || !game.coin_img || !game.player_img || !game.exit_img)
		return (err_free(game.map));
	render_map(&game);
	mlx_loop(game.mlx_ptr);
	free_arr(game.map);
}

