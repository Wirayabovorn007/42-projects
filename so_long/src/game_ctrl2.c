#include "../include/so_long.h"

int	key_press(int keycode, t_game *game)
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

int	key_release(int keycode, t_game *game)
{
	(void)keycode;
	(void)game;
	return (0);
}
