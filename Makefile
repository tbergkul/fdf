# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/13 14:55:32 by tbergkul          #+#    #+#              #
#    Updated: 2020/01/08 11:18:41 by tbergkul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIB = libft/libft.a

INCLUDE = includes/fdf.h

SRC = draw.c window.c save_input.c key_pressed.c main.c ft_error.c

SRCDIR = src/

LIBDIR = libft/

MLX = /usr/local/lib/libmlx.a

SRCS = $(addprefix $(SRCDIR),$(SRC))

CCFL = gcc -g -Wall -Wextra -Werror

.PHONY = all $(NAME) clean fclean re

all: $(NAME)

$(NAME):
	@make -C $(LIBDIR)
	@$(CCFL) -o $(NAME) $(LIB) $(SRCS) $(MLX) -lmlx -framework OpenGL -framework AppKit
	@rm -rf fdf.dSYM

clean:
	@/bin/rm -f $(OBJ)
	@make -C $(LIBDIR) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIBDIR) fclean

re: fclean all
