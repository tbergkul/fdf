/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:36:17 by tbergkul          #+#    #+#             */
/*   Updated: 2019/12/18 15:51:01 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	copy_to_twod_array(t_map *map)
{
	int	y;
	int	x;
	int	i;

	if (!(map->grid = (char **)malloc(sizeof(char *) * map->counter + 1)))
		return (0);
	map->rowlen = ft_strlen(map->temp) / map->counter;
	map->grid[0] = ft_strnew(map->rowlen + 1);
	y = 0;
	i = -1;
	x = -1;
	while (map->temp[++i])
	{
		map->grid[y][++x] = map->temp[i];
		if (x == map->rowlen - 1)
		{
			map->grid[y][++x] = '\0';
			y++;
			x = -1;
			map->grid[y] = ft_strnew(map->rowlen + 1);
		}
	}
	map->grid[y] = NULL;
	return (1);
}

/*
**	11 rader
**	55 characters per rad
*/

int	save_input(char *av, t_map *map)
{
	int		fd;
	char	*line;

	if ((fd = open(av, O_RDONLY)) < 0)
		return (0);
	map->y = 0;
	map->temp = NULL;
	map->counter = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (!map->temp)
			map->temp = ft_strdup(line);
		else
			map->temp = ft_strjoin(map->temp, line);
		map->counter++;
	}
	close(fd);
	ft_putendl("\n----------------- MAP -----------------\n");
	copy_to_twod_array(map);
	print_twod_array(map->grid);//remove when done
	ft_putendl("\n---------------------------------------\n");
	ft_memdel((void **)&map->temp);//working?
	//map->multiplier = 80;
	//map->height = map->counter * map->multiplier;
	//map->width = (map->rowlen / 4) * map->multiplier;
	return (1);
}
