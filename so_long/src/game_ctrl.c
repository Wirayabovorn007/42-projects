
#include "../include/so_long.h"

void	rerender_map(s_game *game, int row, int col, char curr_pos, char di)
{
	if (curr_pos == '0' || curr_pos == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->floor_img, col * IMG_PX, row * IMG_PX);
	if (curr_pos == 'P')
	{
		if (di == 'u')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player_img_u, col * IMG_PX, row * IMG_PX);
		if (di == 'd')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player_img_d, col * IMG_PX, row * IMG_PX);
		if (di == 'l')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player_img_l, col * IMG_PX, row * IMG_PX);
		if (di == 'r')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player_img_r, col * IMG_PX, row * IMG_PX);
	}
}

void	move(int x, int y, s_game *game, char di)
{
	char	**map;
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
	rerender_map(game, game->player.y, game->player.x, '0', di);//rerender only old P point
	game->player.x = x;
	game->player.y = y;
	game->map[y][x] = 'P';
	rerender_map(game, game->player.y, game->player.x, 'P', di);//rerender only new P point
}

void	move_player(char di, s_game *game)
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

int	key_press(int keycode, s_game *game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	if (keycode == KEY_W || keycode == ARROW_U)
		move_player('u', game);
	if (keycode == KEY_A || keycode == ARROW_L)
		move_player('l', game);
	if (keycode == KEY_S || keycode == ARROW_D)
		move_player('d', game);
	if (keycode == KEY_D || keycode == ARROW_R)
		move_player('r', game);
	return (0);
}

int	key_release(int keycode, s_game *game)
{
	(void)keycode;
	(void)game;
	return (0);
}

void	game_control(s_game *game)
{
	mlx_hook(game->win_ptr, 2, 1L<<0, &key_press, game);
	mlx_hook(game->win_ptr, 3, 1L<<1, &key_release, game);
	mlx_hook(game->win_ptr, 17, 0, close_game, game);
}