/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 13:25:21 by ssettle           #+#    #+#             */
/*   Updated: 2019/05/08 12:30:28 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	dispatch_normal(char **format)
{
	ft_putchar(**format); // big issue here
	(*format)++;
	return (1);
}

/*
** The main printf function
*/

int			ft_printf(char *format, ...)
{
	int		count;
	va_list	ap;

	count = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			count += convert_args(&format, ap);
			format++;
		}
		else
			count += dispatch_normal(&format);
	}
	va_end(ap);
	return (count);
}
