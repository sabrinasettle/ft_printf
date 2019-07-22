/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 13:25:21 by ssettle           #+#    #+#             */
/*   Updated: 2019/07/22 13:34:41 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// static int	dispatch_normal(char **format)
// {
// 	ft_putchar(**format);
// 	(*format)++;
// 	return (1);
// }

/*
** The main printf function which uses the va_start macro. Which takes a
** va_list ap and a last_arg. It also uses a type '...' expression, which
** allows access to more then the defined paramaters. va_list ap holds all
** the addtional arguments accessed through va_arg. In the orignal the function
** uses vprintf as well. In this one tho I use my own parser, v_parse.
*/

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int 	done;

	va_start(ap, format);
	done = v_parse(format, ap);
	va_end(ap);
	return (done);
}

//from working with Sam

// done = ftt_vprintf(1, format, arg); three parameterssss

//but pbondoer had this

// result = pf_parse_format(format, list);



// int		count;
// count = 0;
// while (*format != '\0')
// 	{
// 		if (*format == '%')
// 			count += convert_args(&format, ap);
// 		format++;
// 	}