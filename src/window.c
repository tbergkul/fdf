/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:53:04 by tbergkul          #+#    #+#             */
/*   Updated: 2020/01/22 11:15:51 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
**	Get_color will calculate which color to use for the next line.
*/

int		get_color(int z1, int z2)
{
	int	z;

	z = (z2 >= z1) ? z2 : z1;
	if (z < 0)
		return (COLOR_BLUE);
	if (z == 0)
		return (COLOR_WHITE);
	if (z >= 1 && z < 5)
		return (COLOR_YELLOW);
	if (z >= 5 && z < 10)
		return (COLOR_ORANGE);
	return (COLOR_RED);
}

/*
**	The error variable (e) will determine if the next pixel
**	is on the same line or the line below. If it's on the
**	line below, e > 0, y will get incremented by 1 and the
**	error variabel will get corrected.
*/

void	m_negative(t_map *map, int z1, int z2)
{
	int	inc1;
	int	inc2;
	int	e;
	int	i;

	mlx_pixel_put(map->mlx, map->win, map->x1, map->y1, get_color(z1, z2));
	e = (2 * map->dy) - map->dx;
	inc1 = 2 * (map->dy - map->dx);
	inc2 = 2 * map->dy;
	i = -1;
	while (++i < map->dx)
	{
		if (e > 0)
		{
			map->y1 = map->y1 + map->incy;
			e = e + inc1;
		}
		else
			e = e + inc2;
		map->x1 = map->x1 + map->incx;
		mlx_pixel_put(map->mlx, map->win, map->x1, map->y1, get_color(z1, z2));
	}
}

void	m_positive(t_map *map, int z1, int z2)
{
	int	inc1;
	int	inc2;
	int	e;
	int	i;

	mlx_pixel_put(map->mlx, map->win, map->x1, map->y1, get_color(z1, z2));
	e = (2 * map->dx) - map->dy;
	inc1 = 2 * (map->dx - map->dy);
	inc2 = 2 * map->dx;
	i = -1;
	while (++i < map->dy)
	{
		if (e > 0)
		{
			map->x1 = map->x1 + map->incx;
			e = e + inc1;
		}
		else
			e = e + inc2;
		map->y1 = map->y1 + map->incy;
		mlx_pixel_put(map->mlx, map->win, map->x1, map->y1, get_color(z1, z2));
	}
}

/*
**	Bresenham function will calculate the distances between both
**	x-coordinates and y-coordinates and get the absolute value
**	of those distances. If dx > dy, m_negative will be called.
**	In m_negative, the x-value increases by 1 continuosly and
**	the y-value increases by 1 only when changing line.
**	In m_positive, the y-value increases by 1 continuosly and
**	the x-value increases by 1 only when changing line.
*/

void	bresenham(t_map *map, int z1, int z2)
{
	map->dx = map->x2 - map->x1;
	map->dy = map->y2 - map->y1;
	map->dx = abs(map->dx);
	map->dy = abs(map->dy);
	map->incx = (map->x2 > map->x1) ? 1 : -1;
	map->incy = (map->y2 > map->y1) ? 1 : -1;
	if (map->dx > map->dy)
		m_negative(map, z1, z2);
	else
		m_positive(map, z1, z2);
}

/*
**	Window will reset variabels and initiate the connection to the
**	drawing window and call the function draw to draw the 3D map.
*/

int		window(t_map *map)
{
	map->zoom = 0;
	map->rotx = 0;
	map->roty = 0;
	map->startx = 600;
	map->starty = 100;
	map->camera = 1;
	map->z = 0;
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, MAP_WIDTH, MAP_HEIGHT, "FDF");
	draw(map);
	return (0);
}
