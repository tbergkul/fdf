/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:45:21 by tbergkul          #+#    #+#             */
/*   Updated: 2019/12/18 16:02:17 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <fcntl.h>
# include "minilibx/mlx.h"

# include <stdio.h>//remove

# define COLOR_RED 16711680
# define COLOR_GREEN 65280
# define COLOR_YELLOW 16776960
# define COLOR_BLUE 255
# define COLOR_WHITE 16777215
# define COLOR_ORANGE 16742400
# define COLOR_RESET \033[0m

# define KEY_W 87
# define KEY_A 65
# define KEY_S 83
# define KEY_D 68
# define KEY_ESC 27
# define KEY_PLUS 43
# define KEY_MINUS 45

//man ~/Downloads/minilibx/man/man1/mlx_loop.1

typedef struct	s_win
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_win;

typedef struct	s_map
{
	char		**grid;
	char		*temp;
	int			rowlen;
	int			y;
	int			counter;
	int			multiplier;
	int			width;
	int			height;
}				t_map;

int				window(t_map *map);

int				save_input(char *av, t_map *map);

void			ft_error(void);

#endif
