/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 09:04:49 by ssettle           #+#    #+#             */
/*   Updated: 2019/09/11 15:11:45 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t		pf_strlen(const char *str)
{
	int c;

	c = 0;
	while (str[c] != '\0')
		c++;
	return (c);
}

char		*pf_strdup(const char *src)
{
	char	*s2;

	s2 = (char*)malloc(sizeof(*s2) * (pf_strlen(src) + 1));
	if (!s2)
	{
		return (NULL);
	}
	s2 = pf_strcpy(s2, src);
	return (s2);
}
