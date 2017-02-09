# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmurray <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/01 23:11:45 by kmurray           #+#    #+#              #
#    Updated: 2017/02/08 18:13:03 by kmurray          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), clean, fclean, re

NAME= libft

CC= gcc
CFLAGS+= -Wall -Wextra -Werror

SRC_PATH = ./src/
INC_PATH = ./includes/
OBJ_PATH = ./obj/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
INC = $(addprefix -I,$(INC_PATH))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

OBJ_NAME = $(SRC_NAME:.c=.o)
SRC_NAME= ft_itoa.c ft_memdup.c ft_strcmp.c ft_strncpy.c ft_itoa_base.c\
	ft_memmove.c ft_strcpy.c ft_strnequ.c ft_atoi.c ft_lstadd.c ft_memset.c\
	ft_strdel.c ft_strnew.c ft_base_char.c ft_lstdel.c ft_putchar.c\
	ft_strdup.c ft_strnstr.c ft_bzero.c ft_lstdelone.c ft_putchar_fd.c\
	ft_strequ.c ft_strrchr.c ft_count_base.c ft_lstiter.c ft_putendl.c\
	ft_striter.c ft_strsplit.c ft_endspaces.c ft_lstmap.c ft_putendl_fd.c\
	ft_striteri.c ft_strstr.c ft_count_words.c ft_lstnew.c ft_putnbr.c\
	ft_strjoin.c ft_strsub.c ft_isalnum.c ft_memalloc.c ft_putnbr_fd.c\
	ft_strlcat.c ft_strtrim.c ft_isalpha.c ft_memccpy.c ft_putstr.c\
	ft_strlen.c ft_tolower.c ft_isascii.c ft_memchr.c ft_putstr_fd.c\
	ft_strmap.c ft_toupper.c ft_isdigit.c ft_memcmp.c ft_strcat.c\
	ft_strmapi.c ft_wordlen.c ft_isprime.c ft_memcpy.c ft_strchr.c\
	ft_strncat.c ft_isprint.c ft_memdel.c ft_strclr.c ft_strncmp.c\
	ft_power_of.c ft_max.c ft_min.c ft_iswhitespace.c ft_strmove.c\
	ft_strlchr.c ft_freezero.c ft_lstpop.c ft_lstcat.c ft_putlchar.c\
	ft_putlstr.c

all: $(NAME)

$(NAME): $(OBJ)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	@rm -rf $(OBJ_PATH)

fclean: clean

re: fclean all
