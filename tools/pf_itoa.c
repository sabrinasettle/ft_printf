/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 09:55:49 by ssettle           #+#    #+#             */
/*   Updated: 2019/08/31 03:41:41 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
/*
** is taking the number and dividing/getting the reminder of the modolo 10
** modolo will give you the number you lost ex. 126 will give you 6,
** the other side of it
**basiclly how long the string needs to be
*/

char	*ft_itoa(int n)
{
	return (ft_itoa_base(n, 10));
}

static int		get_nbr(uint64_t num)
{
	int			i;

	i = 0;
	while (num)
	{
		num /= 10;
		i += 1;
	}
	return (i);
}

char			*ft_itoa_base_i(int64_t value)
{
	int			len;
	int64_t		ip;
	char		*res;
	static char	index[16] = "0123456789abcdef";

	if (value == 0)
		return (pf_strdup("0"));
	if (!(res = pf_strnew(get_nbr(value))))
		return (NULL);
	ip = value;
	len = (value <= 0) ? 1 : 0;
	while (ip)
	{
		len++;
		ip /= 16;
	}
	ip = value;
	while (len--)
	{
		res[len] = index[ip % 16];
		ip /= 16;
	}
	return (res);
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
