/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:12:32 by tbergkul          #+#    #+#             */
/*   Updated: 2020/01/08 13:13:04 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		coord_x(t_map *map, int x, int y)
{
	return (map->startx - (map->scalex * y) + (map->scalex * x));
}

int		coord_y(t_map *map, int x, int y, int z)
{
	if (z > 25000)
		z = 25000;
	if (z < -25000)
		z = -25000;
	return (map->starty + ((map->scaley) * x) + ((map->scaley) * y) - (z * 2));
}

void	draw_x(t_map *map)
{
	int			i;
	int			j;
	int			k;

	j = -1;
	mlx_string_put(map->mlx, map->win, 20, 20, COLOR_GREEN, "Quit:   ESC");
	mlx_string_put(map->mlx, map->win, 20, 40, COLOR_GREEN, "Move:   W A S D");
	mlx_string_put(map->mlx, map->win, 20, 60, COLOR_GREEN, "Zoom:   + -");
	mlx_string_put(map->mlx, map->win, 20, 80, COLOR_GREEN, "Rotate: < > ^ v");
	while (++j < map->rows - 1)
	{
		k = 0;
		i = -1;
		while (++i < map->rowlen && (map->rowlen + 1 - i) > 0)
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

void	draw_y(t_map *map)
{
	int			i;
	int			j;

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

int		opened(t_map *map)
{
	map->scalex = 20 + map->zoom + map->rotx;
	map->scaley = 20 + map->zoom + map->roty;
	draw_y(map);
	draw_x(map);
	mlx_key_hook(map->win, key_pressed, map);
	mlx_loop(map->mlx);
	return (0);
}
