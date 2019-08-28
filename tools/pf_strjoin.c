/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 14:12:01 by ssettle           #+#    #+#             */
/*   Updated: 2019/08/28 14:12:26 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*pf_strcat(char *dest, const char *src)
{
	char	*nstr;

	nstr = dest;
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (nstr);
}

char	*pf_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	if (!(str = (char*)malloc(pf_strlen(s1) + (pf_strlen(s2) + 1))))
		return (NULL);
	pf_strcpy(str, s1);
	pf_strcat(str, s2);
	return (str);
}