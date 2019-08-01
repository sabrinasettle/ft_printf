/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 10:39:33 by ssettle           #+#    #+#             */
/*   Updated: 2019/07/31 17:51:27 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** 1 width we print only the c, with 2 width we print
** a space AND the c. The only flag for char is l which creates a wint_t.
*/

int		contentsize_width_and_convert(t_opts options, va_list ap)
{
	char	c;
	int		length;

	length = 1;
	if (options.content_size == 0)
		c = va_arg(ap, int);
	else if (options.content_size == 108)
		c = va_arg(ap, wchar_t);
	while (options.width_field >= 1 && !options.flags.minus)
	{
		pf_putchar(' ');
		options.width_field--;
		length++;
	}
	write(1, &c, 1);
	while (options.width_field >= 1 && options.flags.minus)
	{
		pf_putchar(' ');
		options.width_field--;
		length++;
	}
	return (length);
}

int		convert_char(t_opts options, va_list ap)
{
	contentsize_width_and_convert(options, ap);
	return (options.content_size > 1 ? options.content_size : 1);
}
