/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:53:04 by tbergkul          #+#    #+#             */
/*   Updated: 2020/01/21 16:09:53 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
**	Get_color will calculate which color to use for the next line.
*/

int		get_color(int z0, int z1)
{
	int	z;

	z = (z1 >= z0) ? z1 : z0;
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
**
*/

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

/*
**
*/

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

/*
**
*/

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
