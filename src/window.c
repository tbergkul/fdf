/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:53:04 by tbergkul          #+#    #+#             */
/*   Updated: 2020/01/03 16:00:08 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		key_pressed(int key, t_map *map)
{
	if (key == KEY_W)
	{
		map->hy--;
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, map->hx, map->hy, COLOR_GREEN);
		printf("W\n");
	}
	else if (key == KEY_A)
	{
		map->hx--;
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, map->hx, map->hy, COLOR_GREEN);
		printf("A\n");
	}
	else if (key == KEY_S)
	{
		map->hy++;
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, map->hx, map->hy, COLOR_GREEN);
		printf("S\n");
	}
	else if (key == KEY_D)
	{
		map->hx++;
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, map->hx, map->hy, COLOR_GREEN);
		printf("D\n");
	}
	else if (key == KEY_PLUS)
	{
		printf("+\n");
		map->zoom += 10;
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		opened(map);
	}
	else if (key == KEY_MINUS)
	{
		printf("-\n");
		map->zoom -= 10;
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		opened(map);
	}
	else if (key == KEY_ESC)
	{
		printf("Esc\n");
		exit(0);
	}
	else
	{
		printf("key = %d\n", key);
	}
	return (0);
}

/*int		zoom(t_win *win)
{
	map->new_img_ptr = mlx_new_image(map->mlx_ptr, map->x, map->y);
	mlx_pixel_put(map->mlx_ptr, map->new_img_ptr, map->hx, map->hy, COLOR_YELLOW);
	map->hy++;
	mlx_pixel_put(map->mlx_ptr, map->new_img_ptr, map->hx, map->hy, COLOR_YELLOW);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->new_img_ptr, map->x, map->y);
	return (0);
}*/

int		get_colorx(t_map *map, int nb)
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

}

int		get_colory(t_map *map, int nb)
{
	if (nb >= 10)
	{
		if (map->diff_up >= 10)
			map->active_colory = COLOR_RED;
		else
			map->active_colory = COLOR_RED;
	}
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

}

int		get_diff(int nb1, int nb2)//remove and do easier?
{
	return (nb2 - nb1);
}

int		ft_scale(t_map *map)
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
}

void	draw_map(t_map *map)
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
			/*if (line == 0 && nb != map->rowlen - 1)//samma med color
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
			}*/
			//remove?
			/*/
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
			}*/
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
		}
		map->hy += map->size;
	}
}

int		opened(t_map *map)
{
	map->size = 35 + map->zoom;//not to small
	//
	map->x = 1200;
	map->y = 800;
	draw_map(map);
	//printf("keyhook = %d\n", mlx_key_hook(map->win_ptr, key_pressed, win));
	//map->new_img_ptr = mlx_new_image(map->mlx_ptr, map->x, map->y);
	mlx_key_hook(map->win_ptr, key_pressed, map);
	//mlx_new_window(map->mlx_ptr, map->x, map->y, "FDF");
	//draw_map(win, map);
	//mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->new_img_ptr, map->x, map->y);
	mlx_loop(map->mlx_ptr);
	return (0);
}

int		window(t_map *map)
{
	/*t_win	*win;

	if (!(win = (t_win *)malloc(sizeof(t_win))))
		return (-1);*/
	map->x = 1200;
	map->y = 800;
	map->zoom = 0;
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, map->x, map->y, "FDF");
	opened(map);
	return (0);
}
