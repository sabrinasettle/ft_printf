/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:46:03 by ssettle           #+#    #+#             */
/*   Updated: 2019/03/05 21:57:33 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char			*ft_itoa_base(int value, int base)
{
	int			i;
	long		a;
	char		*test;
	static char	*base_str = "0123456789ABCDEF";

	if (value == 0)
		return (ft_strdup("0"));
	i = get_nbr(value, base);
	a = value;
	if (a < 0)
	{
		if (base == 10)
			i++;
		a *= -1;
	}
	if (!(test = (char *)ft_memalloc(sizeof(char) * i + 1)))
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
