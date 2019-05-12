/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 13:25:21 by ssettle           #+#    #+#             */
/*   Updated: 2019/05/12 10:01:26 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

//https://github.com/NicoGGG/ft_printf.2/blob/master/src/ft_printf.c

static int	dispatch_normal(char **format)
{
	pf_putchar(**format);
	(*format)++;
	return (1);
}

/*
** The main printf function which uses the va_start macro. Which takes a
** va_list ap and a last_arg. It also uses a type '...' expression, which
** allows access to more then the defined paramaters. va_list ap holds all
** the addtional arguments accessed through va_arg.
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
