/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 09:55:49 by ssettle           #+#    #+#             */
/*   Updated: 2019/08/28 15:02:19 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
/*
** is taking the number and dividing/getting the reminder of the modolo 10
** modolo will give you the number you lost ex. 126 will give you 6,
** the other side of it
**basiclly how long the string needs to be
*/

char	*pf_itoa(int n)
{
	return (pf_itoa_base(n, 10));
}

char			*pf_itoa_base(int value, int base)
{
	int			len;
	long		i;
	char		*res;
	static char	index[16] = "0123456789abcdef";

	i = value;
	len = (value <= 0) ? 1 : 0;
	while (i)
	{
		len++;
		i /= base;
	}
	i = value;
	if (i < 0)
		i *= -1;
	if (!(res = pf_strnew(len)))
		return (0);
	while (len--)
	{
		res[len] = index[i % base];
		i /= base;
	}
	value < 0 && base == 10 ? res[0] = '-' : 0;
	return (res);
}
