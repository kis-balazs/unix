# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkis <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/07 13:52:49 by bkis              #+#    #+#              #
#    Updated: 2017/07/07 13:52:50 by bkis             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_generate.c
SRC += ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c
SRC += ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c
SRC += ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c
SRC += ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c
SRC += ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c
SRC += ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c
SRC += ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c
SRC += ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c
SRC += ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c
SRC += ft_strjoin.c  ft_strlen.c ft_strmap.c ft_strmerge.c
SRC += ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c
SRC += ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c
SRC += ft_strstr.c ft_strsub.c ft_strtrim.c
SRC += ft_tolower.c ft_toupper.c ft_list_search.c
SRC += ft_strconct.c ft_strnb.c ft_putstr_rev.c
SRC += ft_nbsize.c ft_lenghtwchar.c ft_lenghtstrwchar.c
SRC += ft_printunint.c ft_lenghtunint.c ft_isdir.c
SRC += ft_strint.c ft_stradd.c
SRC += ft_strtrijoin.c ft_strndup.c ft_findstr.c ft_chrstr.c
SRC += get_next_line.c ft_occur.c chreplace.c

DEL = rm -f

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@gcc -o $@ -c $< -I.Includes/

clean:
	@$(DEL) $(OBJ)

fclean: clean
	@$(DEL) $(NAME)

re: fclean all

.PHONY: all clean fclean re
