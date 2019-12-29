/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:36:17 by tbergkul          #+#    #+#             */
/*   Updated: 2019/12/28 17:41:50 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	copy_to_twod_array(t_map *map)
{
	int	y;
	int	x;
	int	i;

	if (!(map->ints = (int **)malloc(sizeof(int *) * map->counter)))
		return (0);
	i = -1;
	map->nbcount = 0;
	while (map->temp[++i])
		if (map->temp[i] != ' ')
		{
			if (i % 18 == 0)
				map->nbcount++;
			else if (map->temp[i] == '0' && map->temp[i - 1] == ' ' && map->temp[i + 1] == ' ')
				map->nbcount++;
			else if (map->temp[i] != '0' && map->temp[i - 1] == ' ')
				map->nbcount++;
		}
	map->rowlen = (map->nbcount / map->counter);
	map->ints[0] = ft_intnew(map->rowlen);
	printf("%d\n%d\n%d\n", map->counter, map->nbcount, map->rowlen);
	y = 0;
	i = -1;
	x = -1;
	printf("%d ", map->ints[0][0]);
	printf("%d ", map->ints[0][1]);
	printf("%d \n", map->ints[0][2]);
	int	**test;
	int	a;
	int	b = 2;
	a = 0;
	if (!(test = (int **)malloc(sizeof(int *) * 2)))
		return (0);
	test[0] = ft_intnew(5);
	while (a < 5)
		test[0][a] = b++;
	printf("%d ", test[0][0]);
	printf("%d ", test[0][1]);
	printf("%d ", test[0][2]);
	printf("%d ", test[0][3]);
	printf("%d \n", test[0][4]);
	while (map->temp[++i])
	{
		if (map->temp[i] != ' ')
		{
			if (map->temp[i] == '0')
				map->ints[y][++x] = 0;
			else
			{
				if (map->temp[i + 1] != ' ')
					map->ints[y][++x] = (ft_atoi(&map->temp[i]) + ft_atoi(&map->temp[i + 1]));
				else
					 map->ints[y][++x] = ft_atoi(&map->temp[i]);
			}
			if (x == map->rowlen - 1)
			{
				y++;
				x = -1;
				map->ints[y] = ft_intnew(map->rowlen);
			}
		}
	}
	printf("%d ", map->ints[0][0]);
	printf("%d ", map->ints[0][1]);
	printf("%d \n", map->ints[0][2]);
	for (x = 0; x < 11; x++)
	{
		for (i = 0; i < 19; i++)
			printf("%d ", map->ints[x][i]);
		printf("\n");
	}
	//map->grid[y] = NULL;
	return (1);
}

/*int	copy_to_twod_array(t_map *map)
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
}*/

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
	map->rows = 0;//onödigt?
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
	//map->rows = map->counter * map->multiplier;
	//map->x = (map->rowlen / 4) * map->multiplier;
	return (1);
}
