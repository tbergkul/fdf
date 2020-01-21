/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:43:55 by tbergkul          #+#    #+#             */
/*   Updated: 2020/01/21 15:48:42 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
**	remove system clear
*/

int	main(int ac, char **av)
{
	t_map	*map;

	system("clear");
	if (ac != 2)
	{
		ft_putendl("usage: ./fdf input_file");
		exit(1);
	}
	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (-1);
	if (!(save_input(av[1], map)))
		return (-1);
	if (!(window(map)))
		return (-1);
	return (0);
}
