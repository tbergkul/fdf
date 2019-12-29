/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 14:53:10 by tbergkul          #+#    #+#             */
/*   Updated: 2019/12/28 17:19:38 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_intnew(size_t size)
{
	int				*ints;
	unsigned int	*ptr;
	size_t			i;

	if (!(ints = (int *)malloc(sizeof(int) * size)))
		return (NULL);
	ptr = (unsigned int *)ints;
	i = 0;
	while (i < size)
	{
		*ptr = 0;
		ptr++;
		i++;
	}
	return (ints);
}
