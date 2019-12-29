/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:53:04 by tbergkul          #+#    #+#             */
/*   Updated: 2019/12/27 14:34:25 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_pressed(int key, t_win *win)
{
	if (key == KEY_W)
	{
		win->hy--;
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, win->hx, win->hy, COLOR_GREEN);
		printf("W\n");
	}
	else if (key == KEY_A)
	{
		win->hx--;
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, win->hx, win->hy, COLOR_GREEN);
		printf("A\n");
	}
	else if (key == KEY_S)
	{
		win->hy++;
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, win->hx, win->hy, COLOR_GREEN);
		printf("S\n");
	}
	else if (key == KEY_D)
	{
		win->hx++;
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, win->hx, win->hy, COLOR_GREEN);
		printf("D\n");
	}
	else if (key == KEY_PLUS)
	{
		printf("+\n");
		win->x -= 200;
		win->y -= 200;
		win->mlx_ptr = mlx_new_image(win->mlx_ptr, win->x, win->y);
	}
	else if (key == KEY_MINUS)
	{
		printf("-\n");
		win->x += 200;
		win->y += 200;
		//win->mlx_ptr = mlx_new_image(win->mlx_ptr, win->x, win->y);
		zoom(win);
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

int	zoom(t_win *win)
{
	win->new_img_ptr = mlx_new_image(win->mlx_ptr, win->x, win->y);
	mlx_pixel_put(win->mlx_ptr, win->new_img_ptr, win->hx, win->hy, COLOR_YELLOW);
	win->hy++;
	mlx_pixel_put(win->mlx_ptr, win->new_img_ptr, win->hx, win->hy, COLOR_YELLOW);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->new_img_ptr, win->x, win->y);
	return (0);
}

void	draw_map(t_win *win, t_map *map)
{
	int	x;
	int	y;

	win->hy = (win->y / 2);
	y = -1;
	while (map->grid[++y])
	{
		x = -1;
		win->hx = (win->x / 2);
		while (map->grid[y][++x])
		{
			if (map->grid[y][x] == '0' && (map->grid[y][x - 1] == ' ' || x == 0))
			{
				mlx_pixel_put(win->mlx_ptr, win->win_ptr, win->hx, win->hy, COLOR_WHITE);
				/*map->lines = -1;
				while (++map->lines < map->size)
				{
					if (y == 0)
						mlx_pixel_put(win->mlx_ptr, win->win_ptr, win->hx + map->lines, win->hy, COLOR_WHITE);
					if (x == 0)
						mlx_pixel_put(win->mlx_ptr, win->win_ptr, win->hx, win->hy + map->lines, COLOR_WHITE);
					mlx_pixel_put(win->mlx_ptr, win->win_ptr, win->hx + map->size, win->hy + map->lines, COLOR_WHITE);
					mlx_pixel_put(win->mlx_ptr, win->win_ptr, win->hx + map->lines, win->hy + map->size, COLOR_WHITE);
				}*/
				win->hx += map->size;
			}
			else if (map->grid[y][x] == '0' && map->grid[y][x - 1] == ' ')
			{
				mlx_pixel_put(win->mlx_ptr, win->win_ptr, win->hx, win->hy, COLOR_WHITE);
				/*map->lines = -1;
				while (++map->lines < map->size)
				{
					if (y == 0)
						mlx_pixel_put(win->mlx_ptr, win->win_ptr, win->hx + map->lines, win->hy, COLOR_WHITE);
					if (x == 0)
						mlx_pixel_put(win->mlx_ptr, win->win_ptr, win->hx, win->hy + map->lines, COLOR_WHITE);
					mlx_pixel_put(win->mlx_ptr, win->win_ptr, win->hx + map->size, win->hy + map->lines, COLOR_WHITE);
					mlx_pixel_put(win->mlx_ptr, win->win_ptr, win->hx + map->lines, win->hy + map->size, COLOR_WHITE);
				}*/
				win->hx += map->size;
			}
			else if (map->grid[y][x] != '0' && map->grid[y][x] != ' ' && (map->grid[y][x + 1] == ' ' || map->grid[y][x + 2] == ' '))
			{
				if (map->grid[y][x + 1] != ' ')
				{
					mlx_pixel_put(win->mlx_ptr, win->win_ptr, win->hx, win->hy, COLOR_RED);
					map->lines = map->size;
					while (map->lines--)
					{
						mlx_pixel_put(win->mlx_ptr, win->win_ptr, win->hx + map->lines, win->hy, COLOR_RED);
						mlx_pixel_put(win->mlx_ptr, win->win_ptr, win->hx, win->hy + map->lines, COLOR_RED);
						//mlx_pixel_put(win->mlx_ptr, win->win_ptr, win->hx + map->size, win->hy + map->lines, COLOR_RED);
						//mlx_pixel_put(win->mlx_ptr, win->win_ptr, win->hx + map->lines, win->hy + map->size, COLOR_RED);
					}
					win->hx += map->size;
				}
				else
				{
					mlx_pixel_put(win->mlx_ptr, win->win_ptr, win->hx, win->hy, COLOR_GREEN);
					/*map->lines = map->size;
					while (map->lines--)
					{
						mlx_pixel_put(win->mlx_ptr, win->win_ptr, win->hx + map->lines, win->hy, COLOR_GREEN);
						mlx_pixel_put(win->mlx_ptr, win->win_ptr, win->hx, win->hy + map->lines, COLOR_GREEN);
						//mlx_pixel_put(win->mlx_ptr, win->win_ptr, win->hx + map->size, win->hy + map->lines, COLOR_GREEN);
						//mlx_pixel_put(win->mlx_ptr, win->win_ptr, win->hx + map->lines, win->hy + map->size, COLOR_GREEN);
					}*/
					win->hx += map->size;
				}
			}
		}
		win->hy += map->size;
	}
}

int	opened(t_win *win, t_map *map)
{
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, win->x, win->y, "Ted");
	map->size = 25;
	draw_map(win, map);
	mlx_key_hook(win->win_ptr, key_pressed, win);
	mlx_loop(win->mlx_ptr);
	return (0);
}

int	window(t_map *map)
{
	t_win	*win;

	//void	*mlx_ptr;
	//void	*win_ptr;
	if (!(win = (t_win *)malloc(sizeof(t_win))))
		return (-1);
	win->x = 1200;
	win->y = 800;
	win->hx = win->x / 2;
	win->hy = win->y / 2;
	/*win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, win->x, win->y, "Ted");
	mlx_pixel_put(win->mlx_ptr, win->win_ptr, 600, 400, COLOR_RED);
	mlx_pixel_put(win->mlx_ptr, win->win_ptr, 601, 401, COLOR_RED);
	mlx_pixel_put(win->mlx_ptr, win->win_ptr, 602, 402, COLOR_RED);
	mlx_pixel_put(win->mlx_ptr, win->win_ptr, 603, 403, COLOR_RED);
	mlx_pixel_put(win->mlx_ptr, win->win_ptr, 604, 404, COLOR_RED);
	mlx_pixel_put(win->mlx_ptr, win->win_ptr, 605, 405, COLOR_RED);*/
	opened(win, map);
	return (0);
}
