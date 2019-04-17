/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 17:55:48 by ssettle           #+#    #+#             */
/*   Updated: 2019/02/27 12:56:22 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *resdst, const void *ressrc, size_t n)
{
	size_t			i;
	unsigned char	*des;
	unsigned char	*src;

	i = 0;
	des = (unsigned char *)resdst;
	src = (unsigned char *)ressrc;
	while (i < n)
	{
		des[i] = src[i];
		i++;
	}
	return (resdst);
}
