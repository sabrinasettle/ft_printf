/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 15:14:14 by ssettle           #+#    #+#             */
/*   Updated: 2019/05/27 15:29:47 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*pf_strdup(const char *src)
{
	char	*s2;

	s2 = (char*)malloc(sizeof(*s2) * (pf_strlen(src) + 1));
	if (!s2)
	{
		return (NULL);
	}
	s2 = ft_strcpy(s2, src);
	return (s2);
}
