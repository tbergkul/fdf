/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:07:28 by tbergkul          #+#    #+#             */
/*   Updated: 2020/01/21 16:08:34 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
**	Draw_instructions will draw the instructions how to navigate/use
**	the program.
*/

void	draw_instructions(t_map *map)
{
	mlx_string_put(map->mlx, map->win, 20, 20, COLOR_GREEN, "Quit:   ESC");
	mlx_string_put(map->mlx, map->win, 20, 40, COLOR_GREEN, "Move:   W A S D");
	mlx_string_put(map->mlx, map->win, 20, 60, COLOR_GREEN, "Zoom:   + -");
	if (map->camera == 1)
	{
		mlx_string_put(map->mlx, map->win, 20, 80, COLOR_GREEN, "Rotate: Arrows");
		mlx_string_put(map->mlx, map->win, 20, 100, COLOR_GREEN, "Adjust z: Q E");
	}
}

int		key_pressed_three(int key, t_map *map)
{
	if (key == KEY_1)
	{
		map->startx = 600;
		map->starty = 100;
		map->camera = 1;
	}
	else if (key == KEY_2)
	{
		map->startx = 450;
		map->starty = 150;
		map->camera = 2;
	}
	map->zoom = 0;
	map->rotx = 0;
	map->roty = 0;
	map->z = 0;
	mlx_clear_window(map->mlx, map->win);
	draw(map);
	return (0);
}

/*
**	system("\n\nLEAKS fdf\n\n");
*/

int		key_pressed_two(int key, t_map *map)
{
	if (key == KEY_PLUS_MAIN || key == KEY_PLUS_NUM)
		map->zoom += 3;
	else if (key == KEY_MINUS_MAIN || key == KEY_MINUS_NUM)
	{
		if (map->zoom > -18)
			map->zoom -= 3;
	}
	else if (key == KEY_ESC)
		exit(0);
	else
		return (key_pressed_three(key, map));
	mlx_clear_window(map->mlx, map->win);
	draw(map);
	return (0);
}

/*
**	Key_pressed functions will determine which key was pressed
**	and act accordingly.
*/

int		key_pressed(int key, t_map *map)
{
	if (key == KEY_W)
		map->starty -= 30;
	else if (key == KEY_A)
		map->startx -= 30;
	else if (key == KEY_S)
		map->starty += 30;
	else if (key == KEY_D)
		map->startx += 30;
	else if (key == ARROW_UP)
		map->roty += 5;
	else if (key == ARROW_DOWN)
		map->roty -= 5;
	else if (key == ARROW_RIGHT)
		map->rotx += 5;
	else if (key == ARROW_LEFT)
		map->rotx -= 5;
	else if (key == KEY_Q)
		map->z += 10;
	else if (key == KEY_E)
		map->z -= 10;
	else
		return (key_pressed_two(key, map));
	mlx_clear_window(map->mlx, map->win);
	draw(map);
	return (0);
}
