/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:45:21 by tbergkul          #+#    #+#             */
/*   Updated: 2020/01/08 13:21:53 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <fcntl.h>
# include "minilibx/mlx.h"

# include <stdio.h>//remove

# define MAP_WIDTH 1280
# define MAP_HEIGHT 720

# define COLOR_RED 16711680
# define COLOR_GREEN 65280
# define COLOR_YELLOW 16776960
# define COLOR_BLUE 255
# define COLOR_WHITE 16777215
# define COLOR_ORANGE 16742400

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_PLUS_MAIN 24
# define KEY_MINUS_MAIN 27
# define KEY_PLUS_NUM 69
# define KEY_MINUS_NUM 78
# define KEY_SPACE 49//remove
# define KEY_1 18
# define KEY_2 19
# define KEY_3 20//remove
# define KEY_ESC 53

# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_DOWN 125
# define ARROW_UP 126

//man ~/Downloads/minilibx/man/man1/mlx_loop.1

typedef struct	s_map
{
	int			nbcount;
	int			rowlen;
	int			rows;
	int			size;
	char		***nbrs;
	void		*mlx;
	void		*win;
	void		*new_img_ptr;//remove?
	int			zoom;
	int			rotx;
	int			roty;
	int			scaley;
	int			scalex;
	int			startx;
	int			starty;
	int			x1;
	int			x2;
	int			y1;
	int			y2;
	int			dx;
	int			dy;
	int			incx;
	int			incy;
}				t_map;

int				key_pressed(int key, t_map *map);

void			bresenham(t_map *map, int z0, int z1);

int				opened(t_map *map);

int				window(t_map *map);

int				save_input(char *av, t_map *map);

void			ft_error(void);

#endif
