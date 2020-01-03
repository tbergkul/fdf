/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:45:21 by tbergkul          #+#    #+#             */
/*   Updated: 2020/01/03 15:59:39 by tbergkul         ###   ########.fr       */
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
//# define COLOR_RESET \033[0m

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_PLUS 24
# define KEY_MINUS 27
# define KEY_ESC 53

# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_DOWN 125
# define ARROW_UP 126

//man ~/Downloads/minilibx/man/man1/mlx_loop.1

/*typedef struct	s_win
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*new_img_ptr;
	int			x;
	int			y;
	int			z;//
	int			hx;
	int			hy;
	int			zoom;
}				t_win;*/

typedef struct	s_map
{
	char		**grid;//remove?
	int			**ints;//remove?
	int			nbcount;//remove?
	char		*temp;//remove?
	int			rowlen;
	int			rows;
	int			counter;//remove?
	int			size;
	int			lines;
	char		***nbrs;//ny
	int			active_colorx;
	int			active_colory;
	int			diff_left;
	int			diff_up;

	void		*mlx_ptr;
	void		*win_ptr;
	void		*new_img_ptr;
	int			x;
	int			y;
	int			z;//
	int			hx;
	int			hy;
	int			zoom;
	int			scaley;
	int			scalex;
}				t_map;

/*typedef struct	s_map       REAL
{
	char		**grid;//remove?
	int			**ints;//remove?
	int			nbcount;//remove?
	char		*temp;//remove?
	int			rowlen;
	int			rows;
	int			counter;//remove?
	int			size;
	int			lines;
	char		***nbrs;//ny
	int			active_colorx;
	int			active_colory;
	int			diff_left;
	int			diff_up;
}				t_map;*/

int				zoom(t_map *map);

int				opened(t_map *map);

int				window(t_map *map);

int				save_input(char *av, t_map *map);

void			ft_error(void);

#endif