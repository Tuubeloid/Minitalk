# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvalimak <tvalimak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/14 18:17:29 by tvalimak          #+#    #+#              #
#    Updated: 2024/02/25 23:20:33 by tvalimak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_strlen.c \
	   ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
	   ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c \
	   ft_atoi.c ft_calloc.c ft_strdup.c ft_memchr.c ft_memcmp.c ft_substr.c ft_strjoin.c \
	   ft_strtrim.c ft_split.c ft_striteri.c ft_strmapi.c ft_putchar_fd.c ft_putnbr_fd.c \
	   ft_putchar_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_itoa.c \

BONUS_SRC = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
		ft_lstmap_bonus.c

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
NAME = libft.a
BONUS_NAME = .bonus
LIBC = ar rcs
CC = gcc
CFLAGS = 

$(BONUS_NAME): $(OBJ) $(BONUS_OBJ)
	$(LIBC) $(NAME) $(OBJ) $(BONUS_OBJ)
	touch $(BONUS_NAME)
	
$(NAME): $(OBJ)
	$(LIBC) $(NAME) $(OBJ)

all: $(NAME)

clean: 
	rm -f $(OBJ) $(BONUS_OBJ) $(BONUS_NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(BONUS_NAME)

.PHONY: all clean fclean re bonus
