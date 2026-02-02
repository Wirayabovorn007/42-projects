#include "../include/so_long.h"

void	rerender_map(t_game *game, char curr_pos, char di)
{
	int	row;
	int	col;

	row = game->player.y;
	col = game->player.x;
	if (curr_pos == '0' || curr_pos == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->floor_img, col * IMG_PX, row * IMG_PX);
	if (curr_pos == 'P')
	{
		if (di == 'u')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->player_img_u, col * IMG_PX, row * IMG_PX);
		if (di == 'd')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->player_img_d, col * IMG_PX, row * IMG_PX);
		if (di == 'l')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->player_img_l, col * IMG_PX, row * IMG_PX);
		if (di == 'r')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->player_img_r, col * IMG_PX, row * IMG_PX);
	}
}

void	move(int x, int y, t_game *game, char di)
{
	char	next_move;

	next_move = game->map[y][x];
	if (next_move == '1')
		return ;
	if (next_move == 'E')
	{
		if (game->player.collect == game->total_colectible)
		{
			ft_printf("Congrat! You have found all the skulls in the game\n");
			close_game(game);
			return ;
		}
		else
			return ;
	}
	if (next_move == 'C')
		game->player.collect += 1;
	game->map[game->player.y][game->player.x] = '0';
	rerender_map(game, '0', di);
	game->player.x = x;
	game->player.y = y;
	game->map[y][x] = 'P';
	rerender_map(game, 'P', di);
}

void	move_player(char di, t_game *game)
{
	int	x;
	int	y;

	x = game->player.x;
	y = game->player.y;
	if (di == 'u')
		y -= 1;
	if (di == 'd')
		y += 1;
	if (di == 'l')
		x -= 1;
	if (di == 'r')
		x += 1;
	move(x, y, game, di);
	game->move_count++;
	ft_printf("You moved %d times\n", game->move_count);
}

void	game_control(t_game *game)
{
	mlx_hook(game->win_ptr, 2, 1L << 0, &key_press, game);
	mlx_hook(game->win_ptr, 3, 1L << 1, &key_release, game);
	mlx_hook(game->win_ptr, 17, 0, close_game, game);
}
