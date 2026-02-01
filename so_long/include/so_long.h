

# ifndef SO_LONG_H
# define SO_LONG_H

#define IMG_PX 32

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../src/get_next_line/get_next_line.h"
#include "../minilibx-linux/mlx.h"

typedef struct s_player{
	int	x;
	int	y;
	int	total_collect;
} s_player;

typedef struct s_game
{
	s_player	player;
	void	*mlx_ptr;
	void	*win_ptr;
	int		map_h;
	int		map_w;
	void	*img_player;
	void *wall_img;
	void *floor_img;
	void *coin_img;
	void *exit_img;
	void *player_img;
	char	**map;
} s_game;


char	**read_map(char *path, int argc);
char	**map_err(char *type);
char	**map_errwf(char *type, char **arr);
void	free_arr(char **arr);
int		len(char *str);
int		ft_strlcmp(char *s1, char *s2, int max);
int		is_validpath(char *path);
void	print_err(char *err);
void	init_game(char **map);
int		get_line_count(char *path);
void	game_control(s_game *game);


#endif