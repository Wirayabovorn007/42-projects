
CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

PRINTF_DIR = ./ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a
INC_DIR = ./include

SRC_C = src/client.c src/utils.c
SRC_S = src/server.c src/utils.c
SRC_C_BONUS = src/client_bonus.c src/utils.c
SRC_S_BONUS = src/server_bonus.c src/utils.c

OBJS_C = $(SRC_C:.c=.o)
OBJS_S = $(SRC_S:.c=.o)
OBJ_C_BONUS = $(SRC_C_BONUS:.c=.o)
OBJ_S_BONUS = $(SRC_S_BONUS:.c=.o)

all: $(CLIENT) $(SERVER)

$(SERVER) : $(OBJS_S) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJS_S) $(PRINTF_LIB) -o $(SERVER)

$(CLIENT) : $(OBJS_C) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJS_C) $(PRINTF_LIB) -o $(CLIENT)

$(PRINTF_LIB) :
	@make -C $(PRINTF_DIR)

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

$(SERVER_BONUS): $(OBJ_S_BONUS) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJ_S_BONUS) $(PRINTF_LIB) -o $(SERVER_BONUS)

$(CLIENT_BONUS): $(OBJ_C_BONUS) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJ_C_BONUS) $(PRINTF_LIB) -o $(CLIENT_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@


clean:
	$(RM) $(OBJS_C) $(OBJS_S)
	@make clean -C $(PRINTF_DIR)

fclean: clean
	$(RM) $(CLIENT) $(SERVER)
	@make fclean -C $(PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re