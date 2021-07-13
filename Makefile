# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldoncker <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/12 15:05:43 by ldoncker          #+#    #+#              #
#    Updated: 2021/07/12 15:05:47 by ldoncker         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

SERVERHEAD = includes/server.h
CLIENTHEAD = includes/client.h

LIBFTDIR = libft
LIBFT = libft/libft.a

SERVERSRC = srcs/server.c srcs/error.c
CLIENTSRC = srcs/client.c srcs/error.c

CC = gcc
FLAGS = -Wall -Wextra -Werror

SERVEROBJ = $(SERVERSRC:.c=.o)
CLIENTOBJ = $(CLIENTSRC:.c=.o)

%.o: %.c $(SERVERHEAD)
	$(CC) $(FLAGS) -c $< -o $@
%.o: %.c $(CLIENTHEAD)
	$(CC) $(FLAGS) -c $< -o $@

all: $(SERVER) $(CLIENT)

$(SERVER): $(SERVEROBJ)
	$(MAKE) all -C $(LIBFTDIR)
	$(MAKE) bonus -C $(LIBFTDIR)
	@echo Compiling $(SERVER)
	ar rcs $(SERVER) $(SERVEROBJ)
	$(CC) $(LIBFT) -o $(SERVER) $(SERVEROBJ)
	@echo $(SERVER) has been created

$(CLIENT): $(CLIENTOBJ)
	@echo Compiling $(CLIENT)
	ar rcs $(CLIENT) $(CLIENTOBJ)
	$(CC) $(LIBFT) -o $(CLIENT) $(CLIENTOBJ)
	@echo $(CLIENT) has been created

clean:
	$(MAKE) clean -C $(LIBFTDIR)
	rm -f $(SERVEROBJ) $(CLIENTOBJ)
	@echo $(SERVEROBJ) and $(CLIENTOBJ) have been cleaned

fclean:
	$(MAKE) fclean -C $(LIBFTDIR)
	rm -f $(SERVEROBJ) $(SERVER) $(CLIENTOBJ) $(CLIENT)
	@echo $(SERVEROBJ), $(SERVER), $(CLIENTOBJ) and $(CLIENT) have been cleaned

re: fclean all
	@echo fclean and make all completed

.PHONY: all clean fclean re
