NAME = so_long
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm

GNL_DIR = src/get_next_line/
SRC_DIR = src/
INC_DIR = include/

GNL_FILES = get_next_line.c  get_next_line_utils.c
SRC_FILES = get_next_line_utils.c  utils.c get_next_line.c  map_controller.c
SRC_OBJS = $(addprefix $(SRC_DIR), $(SRC_FILES))
GNL_OBJS = $(addprefix $(GNL_DIR), $(GNL_FILES))

$(SRC_OBJS)%.o: %.c
$(GNL_OBJS)%.o: %.c

all: $(NAME)

$(NAME): $(SRC_OBJS)
		$(CC) $(FLAGS) main.c
		$(CC) $(FLAGS) $(SRC_OBJS) -o $(NAME)

clean:
	$(RM) -f $(SRC_OBJS)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all

.PHONY: all clean fclean re