/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:36:17 by tbergkul          #+#    #+#             */
/*   Updated: 2020/01/21 15:17:58 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_line(t_map *map, int i, int j, int k)
{
	if (i + 1 == map->rowlen - 1 && j + 1 < map->rows)
		mlx_pixel_put(map->mlx, map->win, map->a + map->scalex, map->b + k,
			get_color(ft_atoi(map->nbrs[j][i]), ft_atoi(map->nbrs[j + 1][i])));
	if (i - 1 >= 0)
		mlx_pixel_put(map->mlx, map->win, map->a - k, map->b,
			get_color(ft_atoi(map->nbrs[j][i]), ft_atoi(map->nbrs[j][i - 1])));
	if (i != map->rowlen - 1)
		mlx_pixel_put(map->mlx, map->win, map->a + k, map->b,
			get_color(ft_atoi(map->nbrs[j][i]), ft_atoi(map->nbrs[j][i + 1])));
	if (j + 1 != map->rows)
		mlx_pixel_put(map->mlx, map->win, map->a, map->b + k,
			get_color(ft_atoi(map->nbrs[j][i]), ft_atoi(map->nbrs[j + 1][i])));
	if (j - 1 >= 0)
		mlx_pixel_put(map->mlx, map->win, map->a, map->b - k,
			get_color(ft_atoi(map->nbrs[j][i]), ft_atoi(map->nbrs[j - 1][i])));
}

void	draw_twod(t_map *map)
{
	int	i;
	int	j;
	int	k;

	j = -1;
	while (++j < map->rows)
	{
		i = -1;
		while (++i < map->rowlen - 1)
		{
			k = -1;
			while (++k < map->scalex)
				draw_line(map, i, j, k);
			map->a += map->scalex;
		}
		map->a = map->startx;
		map->b += map->scaley;
	}
}

/*
**	malloc bra size
*/

int		save_nbrs(t_map *map, int *fd)
{
	char	*line;

	if (!(map->nbrs = (char ***)malloc(sizeof(char **) * 100000 + 1)))
		return (0);
	map->rows = 0;
	while (get_next_line(*fd, &line) > 0)
	{
		map->nbrs[map->rows++] = ft_strsplit(line, ' ');
		ft_memdel((void **)&line);
	}
	map->nbrs[map->rows] = NULL;
	map->rowlen = 0;
	while (map->nbrs[0][map->rowlen])
		map->rowlen++;
	return (1);
}

/*
**	11 rader
**	19 numbers per rad
**	55 characters per rad
**	Totalt antal characters = 11 * 65 = 605
*/

int		save_input(char *av, t_map *map)
{
	int		fd;

	if ((fd = open(av, O_RDONLY)) < 0)
		return (0);
	if (!(save_nbrs(map, &fd)))
		return (0);
	close(fd);
	return (1);
}
