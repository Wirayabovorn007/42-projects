
#include "../include/so_long.h"

int	close_game(s_game *game)
{
	if (game->wall_img)
		mlx_destroy_image(game->mlx_ptr, game->wall_img);
	if (game->floor_img)
		mlx_destroy_image(game->mlx_ptr, game->floor_img);
	if (game->coin_img)
		mlx_destroy_image(game->mlx_ptr, game->coin_img);
	if (game->exit_img)
		mlx_destroy_image(game->mlx_ptr, game->exit_img);
	if (game->player_img_d)
		mlx_destroy_image(game->mlx_ptr, game->player_img_d);
	if (game->player_img_u)
		mlx_destroy_image(game->mlx_ptr, game->player_img_u);
	if (game->player_img_l)
		mlx_destroy_image(game->mlx_ptr, game->player_img_l);
	if (game->player_img_r)
		mlx_destroy_image(game->mlx_ptr, game->player_img_r);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	free_arr(game->map);
	exit(0);
}
