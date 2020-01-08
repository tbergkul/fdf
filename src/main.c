/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:43:55 by tbergkul          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/01/08 12:17:24 by tbergkul         ###   ########.fr       */
=======
/*   Updated: 2020/01/07 13:31:55 by tbergkul         ###   ########.fr       */
>>>>>>> f8401beef5ad235b9f0969dd2152e331e92c5c4d
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int ac, char **av)
{
	t_map	*map;

	system("clear");
	if (ac != 2)
		ft_error();
	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (-1);
	if (!(save_input(av[1], map)))
		return (-1);
	if (!(window(map)))
		return (-1);
	return (0);
}
