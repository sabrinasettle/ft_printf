/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 09:04:49 by ssettle           #+#    #+#             */
/*   Updated: 2019/07/22 14:48:38 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


size_t	pf_strlen(const char *str)
{
	int c;

	c = 0;
	while (str[c] != '\0')
		c++;
	return (c);
}

char	*pf_strcpy(char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
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
