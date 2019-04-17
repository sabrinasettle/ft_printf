/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 09:06:49 by ssettle           #+#    #+#             */
/*   Updated: 2019/03/04 21:37:25 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *need, size_t len)
{
	size_t i;
	size_t need_len;

	if (!*need)
		return ((char*)hay);
	i = 0;
	while (hay[i] && len >= i)
	{
		need_len = 0;
		while (need[need_len] == hay[i + need_len] && i + need_len < len)
		{
			if (!need[need_len++])
				return ((char *)&hay[i]);
			if (need_len != 0 && !need[need_len])
				return ((char *)&hay[i]);
		}
		i++;
	}
	return (NULL);
}
