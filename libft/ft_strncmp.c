/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 09:06:14 by ssettle           #+#    #+#             */
/*   Updated: 2019/03/04 20:42:48 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *tmp1;
	unsigned char *tmp2;

	if (n == 0)
		return (0);
	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	while ((*tmp1 && (*tmp1 == *tmp2)) && --n)
	{
		if (*tmp1 != *tmp2)
			return (*tmp1 - *tmp2);
		tmp1++;
		tmp2++;
	}
	return (*tmp1 - *tmp2);
}
