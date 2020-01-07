/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:43:55 by tbergkul          #+#    #+#             */
/*   Updated: 2020/01/07 13:31:55 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int ac, char **av)
{
	system("clear");
	t_map	*map;

	if (ac != 2)
		ft_error();
	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (-1);
	if (!(save_input(av[1], map)))
		return (-1);
	if (!(window(map)))
		return (-1);
	//system("\n\nLEAKS fdf\n\n");
	return (0);
}
