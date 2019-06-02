/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 15:00:57 by ssettle           #+#    #+#             */
/*   Updated: 2019/05/27 15:03:45 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

char	*pf_itoa(int n)
{
	return (pf_itoa_base(n, 10));
}
