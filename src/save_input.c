/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:36:17 by tbergkul          #+#    #+#             */
/*   Updated: 2020/01/07 15:43:48 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	save_nbrs(t_map *map, int *fd)
{
	char	*line;

	if (!(map->nbrs = (char ***)malloc(sizeof(char **) * /*map->counter*/100000 + 1)))//fixa
		return (0);
	map->rows = 0;
	while (get_next_line(*fd, &line) > 0)
		map->nbrs[map->rows++] = ft_strsplit(line, ' ');
	map->nbrs[map->rows] = NULL;//remove?
	map->rowlen = 0;
	while (map->nbrs[0][map->rowlen])
		map->rowlen++;
	map->nbcount = map->rowlen * map->rows;
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

	if ((fd = open(av, O_RDONLY)) < 0)
		return (0);
	if (!(save_nbrs(map, &fd)))
		return (0);
	close(fd);
	return (1);
}
