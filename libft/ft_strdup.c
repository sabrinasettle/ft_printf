/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 09:04:49 by ssettle           #+#    #+#             */
/*   Updated: 2019/03/04 20:00:10 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *src)
{
	char	*s2;

	s2 = (char*)malloc(sizeof(*s2) * (ft_strlen(src) + 1));
	if (!s2)
	{
		return (NULL);
	}
	s2 = ft_strcpy(s2, src);
	return (s2);
}
