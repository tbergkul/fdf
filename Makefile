# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/13 14:55:32 by tbergkul          #+#    #+#              #
#    Updated: 2020/01/03 16:41:38 by tbergkul         ###   ########.fr        #
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

#MLXLIB = /usr/local/lib/libmlx.a

MLX = libmlx.a

SRCS = $(addprefix $(SRCDIR),$(SRC))

CCFL = gcc -g -Wall -Wextra -Werror

.PHONY = all $(NAME) clean fclean re

# -lmlx -framework OpenGL -framework AppKit
# specify the path to the MinilibX library using the -L flag
# @make -C $(MLXDIR)

#Change this -----------------------------
#MLXLIB = ~/Documents/Code/fdf/

# $(OBJ) $(INCLUDE)

all: $(NAME)

$(NAME):
	@make -C $(LIBDIR)
	@$(CCFL) -o $(NAME) $(LIB) $(SRCS) $(MLX) -L $(MLXDIR) -lmlx -framework OpenGL -framework AppKit

clean:
	@/bin/rm -f $(OBJ)
	@make -C $(LIBDIR) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIBDIR) fclean

re: fclean all
