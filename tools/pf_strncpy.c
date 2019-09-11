/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 11:46:31 by ssettle           #+#    #+#             */
/*   Updated: 2019/09/11 15:09:22 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*pf_strncpy(char *s1, const char *s2, size_t n)
{
	size_t i;

	i = -1;
	while (++i < n && s2[i])
		s1[i] = s2[i];
	while (i < n)
		s1[i++] = '\0';
	return (s1);
}
