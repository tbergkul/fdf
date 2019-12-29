/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:45:21 by tbergkul          #+#    #+#             */
/*   Updated: 2019/12/28 17:47:52 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <fcntl.h>
//# include "minilibx/mlx.h"
#include "../mlx.h"

# include <stdio.h>//remove

# define COLOR_RED 16711680
# define COLOR_GREEN 65280
# define COLOR_YELLOW 16776960
# define COLOR_BLUE 255
# define COLOR_WHITE 16777215
# define COLOR_ORANGE 16742400
# define COLOR_RESET \033[0m

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_PLUS 27
# define KEY_MINUS 44
# define KEY_ESC 53

# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_DOWN 125
# define ARROW_UP 126

//man ~/Downloads/minilibx/man/man1/mlx_loop.1

/*
void struct	s_win
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_win;
*/


typedef struct	s_win
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*new_img_ptr;
	int			x;
	int			y;
	int			z;
	int			hx;
	int			hy;
}				t_win;


typedef struct	s_map
{
	char		**grid;
	int			**ints;
	int			nbcount;
	char		*temp;
	int			rowlen;
	int			rows;
	int			counter;
	int			size;
	int			lines;
}				t_map;

int				zoom(t_win *win);

int				opened(t_win *win, t_map *map);

int				window(t_map *map);

int				save_input(char *av, t_map *map);

void			ft_error(void);

#endif
