NAME        = so_long
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

SRC_DIR     = src/
GNL_DIR     = src/get_next_line/
INC_DIR     = include/


# MLX_FLAGS   = -Lminilibx-linux -lmlx -lXext -lX11 -lm
# INCLUDES    = -I$(INC_DIR) -Iminilibx-linux

INCLUDES    = -I$(INC_DIR)

SRC_FILES   = map_controller.c utils.c
GNL_FILES   = get_next_line.c get_next_line_utils.c
MAIN_FILE   = main.c


SRCS        = $(addprefix $(SRC_DIR), $(SRC_FILES)) \
              $(addprefix $(GNL_DIR), $(GNL_FILES)) \
              $(MAIN_FILE)

OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)


%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re