# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkis <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/05 15:53:15 by bkis              #+#    #+#              #
#    Updated: 2017/07/05 16:36:46 by bkis             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = clang

CFLAGS = -Wall -Wextra -Werror

LIBSRC = 	lib/ft_isdigit.c \
			lib/ft_isescaped.c \
			lib/ft_atoi.c \
			lib/ft_itoa_base.c \
			lib/ft_memset.c \
			lib/ft_nputchar.c \
			lib/ft_strlen.c \
			lib/ft_strlower.c \
			lib/ft_strnew.c \
			lib/ft_strsub.c \
			lib/ft_wstrtostr.c \
			lib/ft_wchartostr.c \
			lib/ft_wstrlen.c \
			lib/ft_tolower.c \
			lib/ft_strcmp.c \
			lib/ft_wcharlen.c \

SRC =	source/ft_printf.c \
		source/ft_display.c \
		source/ft_flags.c \
		source/ft_memory.c \
		source/ft_char_conv.c \
		source/ft_ptr_conv.c \
		source/ft_str_conv.c \
		source/ft_signed_conv.c \
		source/ft_unsigned_conv.c\
		source/ft_wildcard.c\
		$(LIBSRC)\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $^
	@ranlib $@

%.o:%.c
	$(CC) $(CFLAGS) -c -I includes/ -o $@ $^

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
