# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/13 14:55:32 by tbergkul          #+#    #+#              #
#    Updated: 2019/12/18 14:11:04 by tbergkul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIB = libft/libft.a

INCLUDE = includes/fdf.h

SRC = window.c main.c ft_error.c save_input.c

#OBJ = $(SRC:.c=.o)

SRCDIR = src/

LIBDIR = libft/

MLXDIR = includes/minilibx/

# MLX = includes/minilibx/libmlx.a

MLX = /usr/local/lib/libmlx.a

SRCS = $(addprefix $(SRCDIR),$(SRC))

CCFL = gcc -g -Wall -Wextra -Werror

.PHONY = all $(NAME) clean fclean re

# -lmlx -framework OpenGL -framework AppKit
# specify the path to the MinilibX library using the -L flag
# @make -C $(MLXDIR)


# $(OBJ) $(INCLUDE)

all: $(NAME)

$(NAME):
	@make -C $(LIBDIR)
	@$(CCFL) -o $(NAME) $(LIB) $(SRCS) $(MLX) -lmlx -framework OpenGL -framework AppKit

clean:
	@/bin/rm -f $(OBJ)
	@make -C $(LIBDIR) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIBDIR) fclean

re: fclean all
