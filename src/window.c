/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:53:04 by tbergkul          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/01/08 11:55:34 by tbergkul         ###   ########.fr       */
=======
/*   Updated: 2020/01/07 15:55:59 by tbergkul         ###   ########.fr       */
>>>>>>> f8401beef5ad235b9f0969dd2152e331e92c5c4d
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		get_color(int z0, int z1)
{
<<<<<<< HEAD
	z1 = 0;
	if (z0 < 0)
		return (COLOR_BLUE);
	if (z0 == 0)
		return (COLOR_WHITE);
	if (z0 >= 1 && z0 < 5)
		return (COLOR_YELLOW);
	if (z0 >= 5 && z0 < 10)
		return (COLOR_ORANGE);
	return (COLOR_RED);
}

void	m_neg(t_map *map, int z0, int z1)
{
	int	inc1;
	int	inc2;
	int	e;
	int	i;

	i = 0;
	mlx_pixel_put(map->mlx, map->win, map->x1, map->y1, get_color(z0, z1));
	e = (2 * map->dy) - map->dx;
	inc1 = 2 * (map->dy - map->dx);
	inc2 = 2 * map->dy;
	while (i < map->dx)
	{
		if (e >= 0)
		{
			map->y1 = map->y1 + map->incy;
			e = e + inc1;
		}
=======
	if (key == KEY_W)
	{
		map->starty -= 30;
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		opened(map);
	}
	else if (key == KEY_A)
	{
		map->startx -= 30;
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		opened(map);
	}
	else if (key == KEY_S)
	{
		map->starty += 30;
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		opened(map);
	}
	else if (key == KEY_D)
	{
		map->startx += 30;
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		opened(map);
	}
	else if (key == KEY_PLUS)
	{
		map->zoom += 5;
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		opened(map);
	}
	else if (key == KEY_MINUS)
	{
		if (map->zoom > -15)
			map->zoom -= 5;
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		opened(map);
	}
	else if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_SPACE)
	{
		map->zoom = 0;
		map->startx = 600;
		map->starty = 100;
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		opened(map);
	}
	else
		printf("key = %d\n", key);
	return (0);
}

/*int		get_colorx(t_map *map, int nb)
{
	if (nb >= 10)
	{
		if (map->diff_left >= 10)
			map->active_colorx = COLOR_RED;
		else
			map->active_colorx = COLOR_RED;
	}
	else if (nb >= 5 && nb <= 9)
	{
		//if ((diff >= 5 && diff <= 9))
		map->active_colorx = COLOR_ORANGE;
	}
	else if (nb >= 1 && nb <= 4)
	{
		if ((map->diff_left >= 1 && map->diff_left <= 4))
			map->active_colorx = COLOR_YELLOW;
	}
	else if (nb < 0)
		map->active_colorx = COLOR_BLUE;
	return (map->active_colorx);

}*/

/*int		get_colory(t_map *map, int nb)
{
	if (nb >= 10)
	{
		if (map->diff_up >= 10)
			map->active_colory = COLOR_RED;
>>>>>>> f8401beef5ad235b9f0969dd2152e331e92c5c4d
		else
			e = e + inc2;
		map->x1 = map->x1 + map->incx;
		mlx_pixel_put(map->mlx, map->win, map->x1, map->y1, get_color(z0, z1));
		i++;
	}
<<<<<<< HEAD
}

void	m_pos(t_map *map, int z0, int z1)
{
	int	inc1;
	int	inc2;
	int	e;
	int	i;

	i = 0;
	mlx_pixel_put(map->mlx, map->win, map->x1, map->y1, get_color(z0, z1));
	e = (2 * map->dx) - map->dy;
	inc1 = 2 * (map->dx - map->dy);
	inc2 = 2 * map->dx;
	while (i < map->dy)
	{
		if (e >= 0)
		{
			map->x1 = map->x1 + map->incx;
			e = e + inc1;
=======
	else if (nb >= 5 && nb <= 9)
	{
		//if ((diff >= 5 && diff <= 9))
		map->active_colory = COLOR_ORANGE;
	}
	else if (nb >= 1 && nb <= 4)
	{
		if ((map->diff_up >= 1 && map->diff_up <= 4))
			map->active_colory = COLOR_YELLOW;
	}
	else if (nb < 0)
		map->active_colorx = COLOR_BLUE;
	return (map->active_colory);
}*/

/*int		get_diff(int nb1, int nb2)//remove and do easier?
{
	return (nb2 - nb1);
}*/

/*int		ft_scale(t_map *map)
{
	if (map->size >= 35)
	{
		map->scaley = map->size / 10;
		map->scalex = map->scaley + 1;
	}
	else if (map->size == 25 || map->size == 15 || map->size == 5)
	{
		map->scaley = 2;
		map->scalex = 3;
	}
	printf("size = %d\nscaley = %d\nscalex = %d\n", map->size, map->scaley, map->scalex);
	return (map->scaley);
}*/

/*void	draw_twod(t_map *map)
{
	int	line;
	int	nb;
	int	x;

	map->hy = (map->y / ft_scale(map));
	line = -1;
	x = 0;
	nb = 0;
	mlx_string_put(map->mlx_ptr, map->win_ptr, 20, 20, COLOR_GREEN, "Quit = ESC");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 20, 40, COLOR_GREEN, "Move = W A S D");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 20, 60, COLOR_GREEN, "Zoom = + -");
	while (map->nbrs[0][nb++])
		map->rowlen++;
	nb = 0;
	while (map->nbrs[++line])//while (map->grid[++y])
	{
		nb = -1;
		map->hx = (map->x / map->scalex);
		while (map->nbrs[line][++nb])//while (map->grid[y][++x])
		{
			//remove?
			if (line == 0 && nb != map->rowlen - 1)//samma med color
			{
				if (map->nbrs[line][nb][x] == '0')
				{
					//mlx_pixel_put(map->mlx_ptr, map->win_ptr, map->hx, map->hy, COLOR_WHITE);
					map->active_colorx = COLOR_WHITE;
					map->lines = -1;
					while (++map->lines < map->size)
						mlx_pixel_put(map->mlx_ptr, map->win_ptr, map->hx + map->lines, map->hy, map->active_colorx);
				}
				else
				{
					mlx_pixel_put(map->mlx_ptr, map->win_ptr, map->hx, map->hy, COLOR_RED);
					map->lines = -1;
					while (++map->lines < map->size)
						mlx_pixel_put(map->mlx_ptr, map->win_ptr, map->hx + map->lines, map->hy, COLOR_RED);
				}
			}
			//remove?
			/
			if (nb == 0 && line != map->rows - 1)
			{
				if (map->nbrs[line][nb][x] == '0')
				{
					map->active_colory = COLOR_WHITE;
					map->lines = -1;
					while (++map->lines < map->size)
						mlx_pixel_put(map->mlx_ptr, map->win_ptr, map->hx, map->hy + map->lines, map->active_colory);
				}
				else
				{
					map->lines = -1;
					while (++map->lines < map->size)
						mlx_pixel_put(map->mlx_ptr, map->win_ptr, map->hx, map->hy + map->lines, COLOR_RED);
				}
			}
			if (map->nbrs[line][nb][x] == '0')
			{
				mlx_pixel_put(map->mlx_ptr, map->win_ptr, map->hx, map->hy, COLOR_WHITE);
				map->lines = -1;
				while (++map->lines < map->size)
				{
					if (line != 0 && line != map->rows)
						mlx_pixel_put(map->mlx_ptr, map->win_ptr, map->hx, map->hy - map->lines, COLOR_WHITE);
					if (nb != 0)
						mlx_pixel_put(map->mlx_ptr, map->win_ptr, map->hx - map->lines, map->hy, COLOR_WHITE);
				}
				map->hx += map->size;
			}
			else if (map->nbrs[line][nb][x] != '0')
			{
				if (nb - 1 >= 0)
					map->diff_left = get_diff(ft_atoi(map->nbrs[line][nb - 1]), ft_atoi(map->nbrs[line][nb]));
				else
					map->diff_left = get_diff(0, ft_atoi(map->nbrs[line][nb]));
				if (line - 1 >= 0)
					map->diff_up = get_diff(ft_atoi(map->nbrs[line - 1][nb]), ft_atoi(map->nbrs[line][nb]));
				else
					map->diff_up = get_diff(0, ft_atoi(map->nbrs[line][nb]));
				get_colorx(map, ft_atoi(map->nbrs[line][nb]));
				get_colory(map, ft_atoi(map->nbrs[line][nb]));
				map->lines = -1;
				while (++map->lines < map->size)
				{
					if (nb - 1 >= 0)
						mlx_pixel_put(map->mlx_ptr, map->win_ptr, map->hx - map->lines, map->hy, map->active_colorx);
					else
						mlx_pixel_put(map->mlx_ptr, map->win_ptr, map->hx - map->lines, map->hy, map->active_colorx);
					if (line - 1 >= 0)
						mlx_pixel_put(map->mlx_ptr, map->win_ptr, map->hx, map->hy - map->lines, map->active_colory);
					else
						mlx_pixel_put(map->mlx_ptr, map->win_ptr, map->hx, map->hy - map->lines, map->active_colory);
					map->active_colorx += 256;
					map->active_colory += 256;
				}
				map->hx += map->size;
			}
>>>>>>> f8401beef5ad235b9f0969dd2152e331e92c5c4d
		}
		else
			e = e + inc2;
		map->y1 = map->y1 + map->incy;
		mlx_pixel_put(map->mlx, map->win, map->x1, map->y1, get_color(z0, z1));
		i++;
	}
}*/

int		get_color(int z0, int z1)
{
	z1 = 0;
	if (z0 < 0)
		return (COLOR_BLUE);
	if (z0 == 0)
		return (COLOR_WHITE);
	if (z0 >= 1 && z0 < 5)
		return (COLOR_YELLOW);
	if (z0 >= 5 && z0 < 10)
		return (COLOR_ORANGE);
	return (COLOR_RED);

}

void	m_neg(t_map *map, int z0, int z1)
{
	int	inc1;
	int	inc2;
	int	e;
	int	i;

	i = 0;
	mlx_pixel_put(map->mlx_ptr, map->win_ptr, map->x1, map->y1, get_color(z0, z1));
	e = (2 * map->dy) - map->dx;
	inc1 = 2 * (map->dy - map->dx);
	inc2 = 2 * map->dy;
	while (i < map->dx)
	{
		if (e >= 0)
		{
			map->y1 = map->y1 + map->incy;
			e = e + inc1;
		}
		else
			e = e + inc2;
		map->x1 = map->x1 + map->incx;
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, map->x1, map->y1, get_color(z0, z1));
		i++;
	}
}

void	m_pos(t_map *map, int z0, int z1)
{
	int	inc1;
	int	inc2;
	int	e;
	int	i;

	i = 0;
	mlx_pixel_put(map->mlx_ptr, map->win_ptr, map->x1, map->y1, get_color(z0, z1));
	e = (2 * map->dx) - map->dy;
	inc1 = 2 * (map->dx - map->dy);
	inc2 = 2 * map->dx;
	while (i < map->dy)
	{
		if (e >= 0)
		{
			map->x1 = map->x1 + map->incx;
			e = e + inc1;
		}
		else
			e = e + inc2;
		map->y1 = map->y1 + map->incy;
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, map->x1, map->y1, get_color(z0, z1));
		i++;
	}
}

void	bresenham(t_map *map, int z0, int z1)
{
	map->dx = map->x2 - map->x1;
	map->dy = map->y2 - map->y1;
	map->dx = abs(map->dx);
	map->dy = abs(map->dy);
	map->incx = (map->x2 > map->x1) ? 1 : -1;
	map->incy = (map->y2 > map->y1) ? 1 : -1;
	if (map->dx > map->dy)
		m_neg(map, z0, z1);
	else
		m_pos(map, z0, z1);
}

int		coord_x(t_map *map, int x, int y)
{
	return (map->startx - (map->scalex * y) + (map->scalex * x));
}

int		coord_y(t_map *map, int x, int y, int z)
{
	if (z > 1000)
		z = 1000;
	if (z < -1000)
		z = -1000;
	return (map->starty + ((map->scaley) * x) + ((map->scaley) * y) - (z * 2));
}

void	draw_x(t_map *map)
{
	int			i;
	int			j;
	int			k;

	i = -1;
	mlx_string_put(map->mlx_ptr, map->win_ptr, 20, 20, COLOR_GREEN, "Quit = ESC");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 20, 40, COLOR_GREEN, "Move = W A S D");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 20, 60, COLOR_GREEN, "Zoom = + -");
	while (++i < map->rows - 1)
	{
		k = 0;
		j = -1;
		while (++j < map->rowlen && (map->rowlen + 1 - j) > 0)
		{
			map->x1 = coord_x(map, j, i);
			map->y1 = coord_y(map, j, i, ft_atoi(map->nbrs[i][j]));
			map->x2 = coord_x(map, j, i + 1);
			map->y2 = coord_y(map, j, i + 1, ft_atoi(map->nbrs[i + 1][j]));
			bresenham(map, ft_atoi(map->nbrs[i][j]), ft_atoi(map->nbrs[i + 1][j]));
		}
	}
}

void	draw_y(t_map *map)
{
	int			i;
	int			j;

	i = -1;
	while (++i < map->rows)
	{
		j = 0;
		while (j < (map->rowlen - 1))
		{
			map->x1 = coord_x(map, j, i);
			map->y1 = coord_y(map, j, i, ft_atoi(map->nbrs[i][j]));
			j++;
			map->x2 = coord_x(map, j, i);
			map->y2 = coord_y(map, j, i, ft_atoi(map->nbrs[i][j]));
			bresenham(map, ft_atoi(map->nbrs[i][j - 1]), ft_atoi(map->nbrs[i][j]));
		}
	}
}

void	bresenham(t_map *map, int z0, int z1)
{
<<<<<<< HEAD
	map->dx = map->x2 - map->x1;
	map->dy = map->y2 - map->y1;
	map->dx = abs(map->dx);
	map->dy = abs(map->dy);
	map->incx = (map->x2 > map->x1) ? 1 : -1;
	map->incy = (map->y2 > map->y1) ? 1 : -1;
	if (map->dx > map->dy)
		m_neg(map, z0, z1);
	else
		m_pos(map, z0, z1);
=======
	map->scalex = 20 + map->zoom;
	map->scaley = 20 + map->zoom;
	draw_y(map);
	draw_x(map);
	mlx_key_hook(map->win_ptr, key_pressed, map);
	mlx_loop(map->mlx_ptr);
	return (0);
>>>>>>> f8401beef5ad235b9f0969dd2152e331e92c5c4d
}

int		window(t_map *map)
{
	map->zoom = 0;
<<<<<<< HEAD
	map->rotx = 0;
	map->roty = 0;
	map->startx = 600;
	map->starty = 100;
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, MAP_WIDTH, MAP_HEIGHT, "FDF");
=======
	map->startx = 600;
	map->starty = 100;
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, MAP_WIDTH, MAP_HEIGTH, "FDF");
>>>>>>> f8401beef5ad235b9f0969dd2152e331e92c5c4d
	opened(map);
	return (0);
}
