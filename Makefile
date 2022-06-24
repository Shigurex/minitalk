CC = cc
CFLAGS = -Wall -Wextra -Werror
MANDATORY_SERVER_SRCS = server.c
BONUS_SERVER_SRCS = server_bonus.c
MANDATORY_SERVER_OBJS = ${MANDATORY_SERVER_SRCS:.c=.o}
BONUS_SERVER_OBJS = ${BONUS_SERVER_SRCS:.c=.o}
SERVER = server
MANDATORY_CLIENT_SRCS = client.c
BONUS_CLIENT_SRCS = client_bonus.c
MANDATORY_CLIENT_OBJS = ${MANDATORY_CLIENT_SRCS:.c=.o}
BONUS_CLIENT_OBJS = ${BONUS_CLIENT_SRCS:.c=.o}
CLIENT = client

ifdef BONUS
	CLIENT_OBJS = $(BONUS_CLIENT_OBJS)
	SERVER_OBJS = $(BONUS_SERVER_OBJS)
else
	CLIENT_OBJS = $(MANDATORY_CLIENT_OBJS)
	SERVER_OBJS = $(MANDATORY_SERVER_OBJS)
endif

all: ${SERVER} ${CLIENT}

${SERVER}: ${SERVER_OBJS}
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) ${SERVER_OBJS} libft/libft.a -o $(SERVER) 

${CLIENT}: ${CLIENT_OBJS}
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) ${CLIENT_OBJS} libft/libft.a -o $(CLIENT)

clean:
	${RM} ${SERVER_OBJS} ${CLIENT_OBJS}
	make clean -C ./libft

fclean: clean
	${RM} ${NAME}
	${RM} ${SERVER}
	${RM} ${CLIENT}
	make fclean -C ./libft

re: fclean all

bonus:
	@make BONUS=1 all

.PHONY: make clean fclean re bonus
