/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:53:04 by tbergkul          #+#    #+#             */
/*   Updated: 2019/12/18 16:02:16 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	zoom_in(int key, void *param)
{
	printf("zoomed in\n");
}

int	window(t_map *map)
{
	t_win	*win;

	map->y = 1;
	//void	*mlx_ptr;
	//void	*win_ptr;
	if (!(win = (t_win *)malloc(sizeof(t_win))))
		return (-1);
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, 1200, 800, "Ted");
	mlx_pixel_put(win->mlx_ptr, win->win_ptr, 600, 400, COLOR_RED);
	mlx_pixel_put(win->mlx_ptr, win->win_ptr, 601, 401, COLOR_RED);
	mlx_pixel_put(win->mlx_ptr, win->win_ptr, 602, 402, COLOR_RED);
	mlx_pixel_put(win->mlx_ptr, win->win_ptr, 603, 403, COLOR_RED);
	mlx_pixel_put(win->mlx_ptr, win->win_ptr, 604, 404, COLOR_RED);
	mlx_pixel_put(win->mlx_ptr, win->win_ptr, 605, 405, COLOR_RED);
	mlx_key_hook(win->win_ptr, zoom_in, (void *)0);
	mlx_loop(win->mlx_ptr);
	//mlx_loop_hook(mlx_ptr, )
	return (0);
}
