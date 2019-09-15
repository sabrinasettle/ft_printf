/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 09:55:49 by ssettle           #+#    #+#             */
/*   Updated: 2019/09/11 15:44:35 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** is taking the number and dividing/getting the reminder of the modolo 10
** modolo will give you the number you lost ex. 126 will give you 6,
** the other side of it
**basiclly how long the string needs to be
*/

char				*pf_itoa_base(int value, int base)
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

char				*pf_itoa(int value)
{
	return (pf_itoa_base(value, 10));
}

static int64_t		signed_get_nbr(int64_t num)
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

char				*pf_itoa_l_2(int64_t value)
{
	int64_t		len;
	int64_t		ip;
	char		*res;
	static char	index[10] = "0123456789";

	ip = value;
	len = (value <= 0) ? 1 : 0;
	if (!(res = pf_strnew(signed_get_nbr(value))))
		return (NULL);
	while (ip)
	{
		len++;
		ip /= 10;
	}
	ip = value;
	while (len--)
	{
		res[len] = index[ip % 10];
		ip /= 10;
	}
	value < 0 ? res[0] = '-' : 0;
	return (res);
}

char				*pf_itoa_unsigned(uint64_t value)
{
	long		len;
	uint64_t	ip;
	char		*res;
	static char	index[10] = "0123456789";

	ip = value;
	len = (value <= 0) ? 1 : 0;
	if (!(res = pf_strnew(get_nbr(value))))
		return (NULL);
	while (ip)
	{
		len++;
		ip /= 10;
	}
	ip = value;
	while (len--)
	{
		res[len] = index[ip % 10];
		ip /= 10;
	}
	return (res);
}
