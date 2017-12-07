# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkis <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/30 14:27:45 by bkis              #+#    #+#              #
#    Updated: 2017/05/15 16:20:54 by bkis             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=minishell
SRCDIR=./src
OBJDIR=./.obj

CC=clang
CFLAGS=-Wall -Werror -Wextra -g -Weverything -Wno-padded -Wno-missing-noreturn
CPPFLAGS=-Iincludes/ -Ilibft/includes

LDFLAGS=-Llibft/
LDLIBS=-lft

LIB=libft/libft.a

# hashlib.c print_env.c getenv.c env_manage.c env.c

SRC=main.c shparse.c access.c cmd.c builtins.c prompt.c \
	myexit.c env_management.c env_builtin.c env_modify.c bi_cd.c cd_try.c \
	setenv_check.c
OBJ=$(SRC:.c=.o)

SRCS=$(addprefix $(SRCDIR)/,$(SRC))
OBJS=$(addprefix $(OBJDIR)/,$(OBJ))

# GCOV, llvm specific
# CFLAGS+=-g -fprofile-arcs -ftest-coverage
# LDFLAGS+=--coverage

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	@$(CC) $^ -o $@ $(LDFLAGS) $(LDLIBS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p .obj
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(LIB):
	make -C libft/

clean:
	-@rm $(OBJS)

doc:
	doxygen docs/dox/discover

covclean:
	-@rm $(OBJS:.o=.gcno)
	-@rm $(OBJS:.o=.gcda)

fclean: clean
	-@rm $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
