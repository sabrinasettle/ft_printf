/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:03:47 by ssettle           #+#    #+#             */
/*   Updated: 2019/02/25 16:06:32 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t ln)
{
	unsigned int i;

	i = 0;
	if (((unsigned char *)src) < ((unsigned char *)dest))
		while (ln--)
			((unsigned char *)dest)[ln] = ((unsigned char *)src)[ln];
	else
	{
		while (i < ln)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}
