/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:12:32 by tbergkul          #+#    #+#             */
/*   Updated: 2020/01/21 16:03:57 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		coord_x(t_map *map, int x, int y)
{
	return (map->startx - (map->scalex * y) + (map->scalex * x));
}

/*
**	Coord_x and coord_y will return the x or y coordinates to be used
**	in the 3D map for each number in the 3D array.
*/

int		coord_y(t_map *map, int x, int y, int z)
{
	if (z > 25000)
		z = 25000;
	if (z < -25000)
		z = -25000;
	if (z != 0)
	{
		return (map->starty + ((map->scaley) * x) +
		((map->scaley) * y) - (z * 2 + map->z));
	}
	else
		return (map->starty + ((map->scaley) * x) + ((map->scaley) * y));
}

/*
**	// && (map->rowlen + 1 - i) > 0) //needed?
**
**	Draw_y will draw the lines in the y-axis in the 3D map.
*/

void	draw_y(t_map *map)
{
	int	i;
	int	j;

	j = -1;
	while (++j < map->rows - 1)
	{
		i = -1;
		while (++i < map->rowlen)
		{
			map->x1 = coord_x(map, i, j);
			map->y1 = coord_y(map, i, j, ft_atoi(map->nbrs[j][i]));
			map->x2 = coord_x(map, i, j + 1);
			map->y2 = coord_y(map, i, j + 1, ft_atoi(map->nbrs[j + 1][i]));
			bresenham(map, ft_atoi(map->nbrs[j][i]),
			ft_atoi(map->nbrs[j + 1][i]));
		}
	}
}

/*
**	Draw_x will draw the lines in the x-axis in the 3D map.
*/

void	draw_x(t_map *map)
{
	int	i;
	int	j;

	j = -1;
	while (++j < map->rows)
	{
		i = 0;
		while (i < (map->rowlen - 1))
		{
			map->x1 = coord_x(map, i, j);
			map->y1 = coord_y(map, i, j, ft_atoi(map->nbrs[j][i]));
			i++;
			map->x2 = coord_x(map, i, j);
			map->y2 = coord_y(map, i, j, ft_atoi(map->nbrs[j][i]));
			bresenham(map, ft_atoi(map->nbrs[j][i - 1]),
			ft_atoi(map->nbrs[j][i]));
		}
	}
}

/*
**	The function draw will call functions to draw either the
**	3D map or the 2D map depending on the camera variable.
*/

int		draw(t_map *map)
{
	if (map->camera == 1)
	{
		map->scalex = 20 + map->zoom + map->rotx;
		map->scaley = 20 + map->zoom + map->roty;
		draw_x(map);
		draw_y(map);
	}
	else
	{
		map->scalex = 20 + map->zoom;
		map->scaley = 20 + map->zoom;
		map->a = map->startx;
		map->b = map->starty;
		draw_twod(map);
	}
	draw_instructions(map);
	mlx_key_hook(map->win, key_pressed, map);
	mlx_loop(map->mlx);
	return (0);
}
