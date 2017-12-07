# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkis <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/15 19:47:53 by bkis              #+#    #+#              #
#    Updated: 2017/05/15 19:47:54 by bkis             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

MLX = -lmlx -framework OpenGL -framework AppKit

SRC = ft_read.c ft_color_argv.c ft_projection.c main.c draw.c mlx_hook.c mlx.c

OBJ = $(SRC:.c=.o)

INC = includes/

all: $(NAME)

$(NAME):
		@make -C ./libft
		@gcc -Wall -Wextra -Werror -I $(INC) -c $(SRC) 
		gcc $(OBJ) -L libft/ -lft -o $(NAME) $(MLX)

clean:
		@make -C ./libft clean
		@/bin/rm -rf $(OBJ)

fclean: clean
		@make -C ./libft fclean
		@/bin/rm -rf $(NAME)

re: fclean all
	
.PHONY: all clean fclean re 	
