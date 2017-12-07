# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkis <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/30 14:52:29 by bkis              #+#    #+#              #
#    Updated: 2017/05/15 16:27:51 by bkis             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
SRCDIR=./src
OBJDIR=./.obj

CC=clang
CFLAGS=-Wall -Werror -Wextra -g
CPPFLAGS=-Iincludes/
ARFLAGS=scr

SRC=ft_itoa.c ft_atoi.c ft_tabmax.c ft_putchar.c ft_putchar_fd.c ft_putstr.c ft_putstr_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_strlen.c ft_strcpy.c ft_strncpy.c ft_strnew.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strsub.c ft_strdup.c ft_strdel.c ft_strclr.c ft_strcmp.c ft_strncmp.c ft_strequ.c ft_strnequ.c ft_strcchr.c ft_strrchr.c ft_strclchr.c ft_strchr.c ft_strstr.c ft_strnstr.c ft_strjoin.c ft_strsplit.c ft_strtrim.c ft_strmap.c ft_strmapi.c ft_striter.c ft_striteri.c ft_strinv.c ft_isupper.c ft_toupper.c ft_tolower.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_isalnum.c ft_bzero.c ft_memset.c ft_memalloc.c ft_realloc.c ft_memdel.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_lstmanage_funcs.c ft_lstadd_funcs.c ft_swap.c ft_getndigits.c get_next_line.c ft_pmem.c ft_mat.c ft_strtdel.c ft_strtnew.c ft_strrmstr.c
OBJ=$(SRC:.c=.o)

SRCS=$(addprefix $(SRCDIR)/,$(SRC))
OBJS=$(addprefix $(OBJDIR)/,$(OBJ))

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(ARFLAGS) $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p .obj
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	-rm $(OBJS)

fclean: clean
	-rm $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
