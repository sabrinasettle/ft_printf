/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 17:55:55 by ssettle           #+#    #+#             */
/*   Updated: 2019/02/27 14:32:23 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *resdst, const void *ressrc, int c, size_t n)
{
	size_t				usi;
	unsigned char		*des;
	unsigned char		*src;

	usi = 0;
	des = (unsigned char *)resdst;
	src = (unsigned char *)ressrc;
	while (usi < n)
	{
		des[usi] = src[usi];
		if ((unsigned char)src[usi] == (unsigned char)c)
			return (des + usi + 1);
		usi++;
	}
	return (NULL);
}
