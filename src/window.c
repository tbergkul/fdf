/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:53:04 by tbergkul          #+#    #+#             */
/*   Updated: 2020/01/08 11:55:34 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
		else
			e = e + inc2;
		map->x1 = map->x1 + map->incx;
		mlx_pixel_put(map->mlx, map->win, map->x1, map->y1, get_color(z0, z1));
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
		}
		else
			e = e + inc2;
		map->y1 = map->y1 + map->incy;
		mlx_pixel_put(map->mlx, map->win, map->x1, map->y1, get_color(z0, z1));
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

int		window(t_map *map)
{
	map->zoom = 0;
	map->rotx = 0;
	map->roty = 0;
	map->startx = 600;
	map->starty = 100;
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, MAP_WIDTH, MAP_HEIGHT, "FDF");
	opened(map);
	return (0);
}
