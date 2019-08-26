/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 09:55:49 by ssettle           #+#    #+#             */
/*   Updated: 2019/08/23 10:09:40 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
/*
** is taking the number and dividing/getting the reminder of the modolo 10
** modolo will give you the number you lost ex. 126 will give you 6,
** the other side of it
**basiclly how long the string needs to be
*/

static int		get_nbr(int a, int base)
{
	int			i;

	i = 0;
	while (a)
	{
		a /= base;
		i += 1;
	}
	return (i);
}

char			*pf_itoa_base(int value, int base)
{
	int			i;
	long		a;
	char		*test;
	static char	*base_str = "0123456789ABCDEF";

	if (value == 0)
		return (pf_strdup("0"));
	i = get_nbr(value, base);
	a = value;
	if (a < 0)
	{
		if (base == 10)
			i++;
		a *= -1;
	}
	if (!(test = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	test[i] = '\0';
	while (a)
	{
		test[--i] = base_str[a % base];
		a /= base;
	}
	value < 0 && base == 10 ? test[0] = '-' : 0;
	return (test);
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