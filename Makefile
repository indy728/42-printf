# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmurray <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/01 23:11:45 by kmurray           #+#    #+#              #
#    Updated: 2017/03/22 02:18:22 by kmurray          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), clean, fclean, re, test

NAME= libftprintf.a

CC= gcc
CFLAGS+= -Wall -Wextra -Werror

SRC_PATH = src/
INC_PATH = includes/
OBJ_PATH = obj/

LIBFT_PATH= ./libft/
LIBPF_PATH= ./libprintf/

LIBFT_INC = $(addprefix $(LIBFT_PATH),$(INC_PATH))
LIBPF_INC = $(addprefix $(LIBPF_PATH),$(INC_PATH))

LIBFT_OBJ = $(addprefix $(LIBFT_PATH),$(OBJ_PATH))
LIBPF_OBJ = $(addprefix $(LIBPF_PATH),$(OBJ_PATH))

LIBFT_SRC = $(addprefix $(LIBFT_PATH),$(SRC_PATH))
LIBPF_SRC = $(addprefix $(LIBPF_PATH),$(SRC_PATH))

LIBFT_OBJ_NAME = $(LIBFT_SRC_NAME:.c=.o)
LIBPF_OBJ_NAME = $(LIBPF_SRC_NAME:.c=.o)

LIBFT_SRC_NAME= ft_itoa.c ft_memdup.c ft_strcmp.c ft_strncpy.c ft_lltoa_base.c\
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
		  ft_putlstr.c ft_putlnbr.c ft_putlnbr_fd.c ft_exit_malloc_error.c\
		  ft_maxtoa_base.c ft_umaxtoa_base.c ft_countu_base.c\
		  ft_toupperstr.c

LIBPF_SRC_NAME= ft_printf.c char_at_x.c parse_fmt.c parse_mods.c parse_flags.c\
			parse_fw.c parse_precision.c parse_specifier.c print_mods.c\
			parse_length.c validate_mods.c validate_flags.c\
			get_udecimal.c make_decimalstr.c make_stringstr.c make_pointerstr.c\
			make_octalstr.c make_hexstr.c\
			add_precision.c add_padding.c


OBJ = $(addprefix $(LIBFT_OBJ),$(LIBFT_OBJ_NAME))\
	  $(addprefix $(LIBPF_OBJ),$(LIBPF_OBJ_NAME))

all: $(NAME)

$(LIBFT_OBJ)%.o: $(LIBFT_SRC)%.c
	@mkdir -p $(LIBFT_OBJ)
	@$(CC) $(CFLAGS) -I $(LIBFT_INC) -o $@ -c $<	

$(LIBPF_OBJ)%.o: $(LIBPF_SRC)%.c
	@mkdir -p $(LIBPF_OBJ)
	@$(CC) $(CFLAGS) -I $(LIBFT_INC) -I $(LIBPF_INC) -o $@ -c $<	

$(NAME): $(OBJ)
	ar -rcs $(NAME) $?
	ranlib $(NAME)

test:
	$(CC) $(CFLAGS) main.c -I $(LIBFT_INC) -I $(LIBPF_INC) -L. -lftprintf -o test

clean:
	rm -rf $(LIBFT_OBJ) $(LIBPF_OBJ)

fclean: clean
	rm -f $(NAME) test

re: fclean all
