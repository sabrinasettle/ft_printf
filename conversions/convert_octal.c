/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_octal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 12:33:46 by ssettle           #+#    #+#             */
/*   Updated: 2019/07/18 09:27:27 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*octal_create(iptr_t int_ptr) //correct parameters???
{
	int		i;
	char	*res;
	char	*octal;

	if(!(res = (char *)malloc(sizeof(char*))))
		return(-1);
	octal = "01234567";
	if (!int_ptr)
		res[i] = '0';
	while (int_ptr)
	{
		res[i] = octal[int_ptr % 8];
		int_ptr /= 8;
		i++;
	}
	res = ft_strlen(res);
	return (res);
}

int			convert_octal(t_opts options, va_list ap)
{
	octal_create()
}


// if (!(str = ft_itoa_base(num, 8, 'a')))
// 		exit(-1);

// str = pf_itoa(n, param, sign);

// char			*ft_itoa_base(int value, int base)
// others take three parameters looks like , intmax_t, a number or struct, and a char