/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 09:34:34 by ssettle           #+#    #+#             */
/*   Updated: 2019/09/11 15:28:30 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		v_parse(const char *format, va_list ap)
{
	size_t i;
	size_t len;

	i = 0;
	len = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			len += convert_args(&format, ap);
		}
		else
			len += int_putchar(*format);
		format += 1;
	}
	return (len);
}
