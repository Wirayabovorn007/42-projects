NAME		= so_long
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
MLX_PATH	= minilibx-linux
MLX_LIB		= $(MLX_PATH)/libmlx_Linux.a
MLX_FLAGS	= -L$(MLX_PATH) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

SRCS		= main.c \
			  src/game_init.c \
			  src/close_game.c \
			  src/path_check.c \
			  src/game_ctrl.c \
			  src/map_init.c \
			  src/utils.c \
			  src/get_next_line/get_next_line.c \
			  src/get_next_line/get_next_line_utils.c \
			  src/ft_printf/ft_printf.c \
			  src/ft_printf/cs_handler.c \
			  src/ft_printf/idu_handler.c \
			  src/ft_printf/u_handler.c \
			  src/ft_printf/all_x_handler.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(MLX_LIB):
	make -C $(MLX_PATH)

$(NAME): $(OBJS) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)
	make -C $(MLX_PATH) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re