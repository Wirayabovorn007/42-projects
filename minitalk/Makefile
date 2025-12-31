
CLIENT = client
SERVER = server

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

PRINTF_DIR = ./ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a
INC_DIR = ./include

SRC_C = src/client.c src/utils.c
SRC_S = src/server.c src/utils.c

OBJS_C = $(SRC_C:.c=.o)
OBJS_S = $(SRC_S:.c=.o)

all: $(CLIENT) $(SERVER)

$(SERVER) : $(OBJS_S) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJS_S) $(PRINTF_LIB) -o $(SERVER)

$(CLIENT) : $(OBJS_C) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJS_C) $(PRINTF_LIB) -o $(CLIENT)

$(PRINTF_LIB) :
	@make -C $(PRINTF_DIR)

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