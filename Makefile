# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvalimak <Tvalimak@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/03 14:41:40 by tvalimak          #+#    #+#              #
#    Updated: 2024/02/12 10:43:03 by tvalimak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#CFLAGS = -Wall -Werror -Wextra
#CC = gcc
#SERVER = server
#CLIENT = client
#PRINTF = ./ft_printf/libftprintf.a

#SRC_CLIENT = client.c
#OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

#SRC_SERVER = server.c
#OBJ_SERVER = $(SRC_SERVER:.c=.o)

#$(PRINTF):
#	@make -C ./ft_printf

#all: $(SERVER) $(CLIENT)

#$(SERVER): $(OBJ_SERVER)
#	$(MAKE) -C ./ft_printf
#	$(CC) $(CFLAGS) $(OBJ_SERVER) $(PRINTF) -o $(SERVER)

#$(CLIENT): $(OBJ_CLIENT)
#	$(MAKE) -C ./ft_printf
#	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(PRINTF) -o $(CLIENT)
	
#	$(PRINTF)
#	$(CC) $(CFLAGS) server.c -o $(PRINTF)
#	$(CC) $(CFLAGS) client.c -o $(CLIENT) $(PRINTF)
#	@echo "Server And Client Are Ready!"
	
#clean:
#	@make clean -s -C ft_printf

#fclean: clean
#	@make fclean -s -C ft_printf
#	@rm -f $(SERVER) $(CLIENT)
#	@echo "Server and Client Have Been Cleaned Successfully"

#re: fclean all

#.phony: all clean fclean re

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME_CLIENT = client
NAME_SERVER = server

PRINTF = ./ft_printf/libftprintf.a

SRC_CLIENT = client.c
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

SRC_SERVER = server.c
OBJ_SERVER = $(SRC_SERVER:.c=.o)

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT)
	$(MAKE) -C ./ft_printf
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(PRINTF) -o $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(PRINTF) -o $(NAME_SERVER)

clean:
	$(MAKE) clean -C ./ft_printf
	rm -rf $(OBJ_CLIENT) $(OBJ_SERVER)

fclean: clean
	$(MAKE) fclean -C ./ft_printf
	rm -rf $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all

.PHONY: all bonus clean fclean re libft



























