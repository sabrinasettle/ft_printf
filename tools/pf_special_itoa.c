/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_special_itoa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 14:04:17 by ssettle           #+#    #+#             */
/*   Updated: 2019/08/28 14:10:55 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

char			*pf_itoa_p(intptr_t value)
{
	int			len;
	intptr_t	ip;
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

char	*pf_itoa_hex(int n)
{
	return (pf_itoa_base(n, 16));
}

char	*pf_itoa(int n)
{
	return (pf_itoa_base(n, 10));
}

char	*pf_itoa_octal(int n)
{
	return (pf_itoa_base(n, 8));
}