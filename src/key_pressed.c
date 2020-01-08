/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:07:28 by tbergkul          #+#    #+#             */
/*   Updated: 2020/01/08 13:16:00 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_pressed_four(int key, t_map *map)
{
	if (key == KEY_ESC)
	{
		//system("\n\nLEAKS fdf\n\n");
		exit(0);
	}
	else if (key == KEY_1)
	{
		map->zoom = 0;
		map->rotx = 0;
		map->roty = 0;
		map->startx = 600;
		map->starty = 100;
		mlx_clear_window(map->mlx, map->win);
		opened(map);
	}
	else if (key == KEY_2)
	{
		map->zoom = 0;
		map->rotx = 0;
		map->roty = -20;
		map->startx = 600;
		map->starty = 300;
		mlx_clear_window(map->mlx, map->win);
		opened(map);
	}
	else if (key == KEY_3)
	{
		map->zoom = 0;
		map->rotx = 100;
		map->roty = 0;
		map->startx = 600;
		map->starty = 100;
		mlx_clear_window(map->mlx, map->win);
		opened(map);
	}
	return (0);
}

int	key_pressed_three(int key, t_map *map)
{
	if (key == KEY_PLUS_MAIN || key == KEY_PLUS_NUM)
	{
		map->zoom += 5;
		mlx_clear_window(map->mlx, map->win);
		opened(map);
	}
	else if (key == KEY_MINUS_MAIN || key == KEY_MINUS_NUM)
	{
		map->zoom -= 5;
		mlx_clear_window(map->mlx, map->win);
		opened(map);
	}
	return (key_pressed_four(key, map));
}

int	key_pressed_two(int key, t_map *map)
{
	if (key == ARROW_UP)
	{
		map->roty += 5;
		mlx_clear_window(map->mlx, map->win);
		opened(map);
	}
	else if (key == ARROW_DOWN)
	{
		map->roty -= 5;
		mlx_clear_window(map->mlx, map->win);
		opened(map);
	}
	else if (key == ARROW_RIGHT)
	{
		map->rotx += 5;
		mlx_clear_window(map->mlx, map->win);
		opened(map);
	}
	else if (key == ARROW_LEFT)
	{
		map->rotx -= 5;
		mlx_clear_window(map->mlx, map->win);
		opened(map);
	}
	return (key_pressed_three(key, map));
}

int	key_pressed(int key, t_map *map)
{
	if (key == KEY_W)
	{
		map->starty -= 30;
		mlx_clear_window(map->mlx, map->win);
		opened(map);
	}
	else if (key == KEY_A)
	{
		map->startx -= 30;
		mlx_clear_window(map->mlx, map->win);
		opened(map);
	}
	else if (key == KEY_S)
	{
		map->starty += 30;
		mlx_clear_window(map->mlx, map->win);
		opened(map);
	}
	else if (key == KEY_D)
	{
		map->startx += 30;
		mlx_clear_window(map->mlx, map->win);
		opened(map);
	}
	return (key_pressed_two(key, map));
}
