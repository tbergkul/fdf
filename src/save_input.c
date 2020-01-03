/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:36:17 by tbergkul          #+#    #+#             */
/*   Updated: 2020/01/03 14:54:34 by tbergkul         ###   ########.fr       */
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

/*int	copy_to_nbrs(t_map *map)
{
	int	y;
	int	x;
	int	i;

	if (!(map->nbrs = (char ***)malloc(sizeof(char **) * map->counter + 1)))
		return (0);
	map->rowlen = ft_strlen(map->temp) / map->counter;
	printf("len temp = %zu\nmap->counter = %d\nmap->rowlen = %d\n", ft_strlen(map->temp), map->counter, map->rowlen);
	map->nbr = ft_strsplit(map->temp, ' ');
	//if (!(map->nbrs[0] = (char **)malloc(sizeof(char *) * map->counter + 1)))
	//	return (0);
	//map->nbrs[0] = ft_strnew(map->rowlen + 1);
	//printf("%s\n%s\n%s\n", map->nbr[0], map->nbr[1], map->nbr[2]);
	print_twod_array(map->nbr);
	printf("\n----\n");
	return (1);
}*/

int	save_nbrs(t_map *map, int *fd)
{
	char	*line;

	if (!(map->nbrs = (char ***)malloc(sizeof(char **) * /*map->counter*/100000 + 1)))//fixa
		return (0);
	map->rows = 0;
	while (get_next_line(*fd, &line) > 0)
	{
		if (!map->nbrs)
			map->nbrs[map->rows] = ft_strsplit(line, ' ');
		else
			map->nbrs[map->rows] = ft_strsplit(line, ' ');
		map->rows++;
	}
	map->nbrs[map->rows] = NULL;//remove?
	return (1);
}

/*
**	11 rader
**	19 numbers per rad
**	55 characters per rad
**	Totalt antal characters = 11 * 65 = 605
*/

int	save_input(char *av, t_map *map)
{
	int		fd;
	//char	*line;

	if ((fd = open(av, O_RDONLY)) < 0)
		return (0);
	map->rows = 0;//onödigt?
	map->temp = NULL;//remove?
	map->counter = 0;//remove?
	if (!(save_nbrs(map, &fd)))
		return (0);
	/*while (get_next_line(fd, &line) > 0)
	{
		if (!map->temp)
			map->temp = ft_strdup(line);
		else
			map->temp = ft_strjoin(map->temp, line);
		map->counter++;
	}*/
	close(fd);
	ft_putendl("\n----------------- MAP -----------------\n");
	//if (!(copy_to_twod_array(map)))
	//	return (0);
	//printf("\n--3--\n");
	/*if (!(copy_to_nbrs(map)))
		return (0);*/
	//print_twod_array(map->grid);//remove when done
	//printf("\n-----\n");
	//print_threed_array(map->nbrs);
	//printf("\n-----\n");
	ft_putendl("\n---------------------------------------\n");
	//ft_memdel((void **)&map->temp);//remove?
	//map->multiplier = 80;
	//map->height = map->counter * map->multiplier;
	//map->width = (map->rowlen / 4) * map->multiplier;
	//map->rows = map->counter * map->multiplier; senare
	//map->x = (map->rowlen / 4) * map->multiplier; senare
	return (1);
}
