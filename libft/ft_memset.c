/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 17:56:08 by ssettle           #+#    #+#             */
/*   Updated: 2019/02/26 16:03:40 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t ln)
{
	unsigned char *vc;

	vc = (unsigned char *)b;
	if (ln == 0)
		return (b);
	while (ln--)
	{
		*vc++ = (unsigned char)c;
	}
	return (b);
}
