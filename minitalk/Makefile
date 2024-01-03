SERVER = server
CLIENT = client
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

SERVER_SRC		=	server.c
SERVER_BSRC		=	server_bonus.c
CLIENT_SRC		=	client.c
CLIENT_BSRC		=	client_bonus.c

UTILS_SRC	= minitalk_utils_bonus.c

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)
SERVER_B_OBJS = $(SERVER_BSRC:.c=.o)
CLIENT_B_OBJS = $(CLIENT_BSRC:.c=.o)
UTILS_OBJ	= $(UTILS_SRC:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror
CC = gcc

all: $(SERVER) $(CLIENT)

$(SERVER) : $(SERVER_OBJ)
	$(CC) $(CFLAGS) $(SERVER_OBJ) -o $(SERVER)

$(SERVER_OBJ): $(SERVER_SRC)
	$(CC) $(CFLAGS) -c $(SERVER_SRC) -o $(SERVER_OBJ)

$(CLIENT) : $(CLIENT_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) -o $(CLIENT)

$(CLIENT_OBJ): $(CLIENT_SRC)
	$(CC) $(CFLAGS) -c $(CLIENT_SRC) -o $(CLIENT_OBJ)

bonus : $(SERVER_BONUS) $(CLIENT_BONUS)


$(SERVER_BONUS) : $(SERVER_B_OBJS)
	$(CC) $(CFLAGS) $(SERVER_B_OBJS) -o $(SERVER_BONUS)

$(SERVER_B_OBJS): $(SERVER_BSRC)
	$(CC) $(CFLAGS) -c $(SERVER_BSRC) -o $(SERVER_B_OBJS)

$(CLIENT_BONUS) : $(CLIENT_B_OBJS) $(UTILS_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_B_OBJS) $(UTILS_OBJ) -o $(CLIENT_BONUS)

$(CLIENT_B_OBJS): $(CLIENT_BSRC)
	$(CC) $(CFLAGS) -c $(CLIENT_BSRC) -o $(CLIENT_B_OBJS)

$(UTILS_OBJ) : $(UTILS_SRC)
	$(CC) $(CFLAGS) -c $(UTILS_SRC) -o $(UTILS_OBJ)

clean :
		$(RM) $(SERVER_OBJ) $(CLIENT_OBJ) $(SERVER_B_OBJS) $(CLIENT_B_OBJS) $(UTILS_OBJ)

fclean : clean
		$(RM) $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS) 

re : fclean all

.PHONY: all clean fclean re bonus
