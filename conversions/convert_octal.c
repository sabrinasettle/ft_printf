/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_octal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 12:33:46 by ssettle           #+#    #+#             */
/*   Updated: 2019/07/10 20:36:06 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*octal_create(iptr_t int_ptr)
{
	int		i;
	char	*res;
	char	*octal

	if (!(res = (char *)malloc(sizeof(char) * )))
	octal = "01234567";
	if (!int_ptr)
		res[i] = '0';
	while (int_ptr)
	{
		res[i] = octal[int_ptr % 8];
		int_ptr /= 8;
		i++;
	}
	res = pf_strlen(res);
	return (res);
}

int			convert_octal(t_opts options, va_list ap)
{
	char res;
	char octal;
	int len;

	if (opts.width > len)
		res = pad_octal(s, len, options);
}
