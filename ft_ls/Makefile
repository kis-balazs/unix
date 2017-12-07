# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkis <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/11 12:36:53 by bkis              #+#    #+#              #
#    Updated: 2017/03/11 13:08:15 by bkis             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_ls
SRCDIR=./src
OBJDIR=./obj

CC=clang
CFLAGS=-Wall -Werror -Wextra -g 
CPPFLAGS=-Iincludes/ -Ilibft/includes

LDFLAGS=-Llibft/
LDLIBS=-lft

LIB=libft/libft.a

SRC=ft_ls.c lsfile.c lists.c loadinfo.c params.c output.c utils.c
OBJ=$(SRC:.c=.o)

SRCS=$(addprefix $(SRCDIR)/,$(SRC))
OBJS=$(addprefix $(OBJDIR)/,$(OBJ))

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	@$(CC) $^ -o $@ $(LDFLAGS) $(LDLIBS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(LIB):
	@make -C libft/

clean:
	@rm $(OBJS)
	@rm -rf	./obj

fclean: clean
	@rm $(NAME)

re: fclean all
