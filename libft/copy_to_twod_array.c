/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_to_twod_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:36:17 by tbergkul          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/01/08 11:06:04 by tbergkul         ###   ########.fr       */
=======
/*   Updated: 2020/01/07 15:40:54 by tbergkul         ###   ########.fr       */
>>>>>>> f8401beef5ad235b9f0969dd2152e331e92c5c4d
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**copy_to_twod_array(char *str, int rowlen, int rows)
{
	char	**array;
	int		y;
	int		x;
	int		i;

	if (!(array = (char **)malloc(sizeof(char *) * rows + 1)))
		return (NULL);
	array[0] = ft_strnew(rowlen + 1);
	i = -1;
	y = 0;
	x = -1;
	while (str[++i])
	{
		array[y][++x] = str[i];
		if (x == rowlen - 1)
		{
			array[y][++x] = '\0';
			y++;
			x = -1;
			array[y] = ft_strnew(rowlen + 1);
		}
	}
	array[y] = NULL;
	return (array);
}
