/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 13:25:21 by ssettle           #+#    #+#             */
/*   Updated: 2019/05/07 15:23:26 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	dispatch_normal(char **str)
{
	ft_putchar(*str);
	(*str)++;
	return (1);
}

/*
** The main printf function
*/

int			ft_printf(char *str, ...)
{
	int		count;
	va_list	ap;

	count = 0;
	va_start(ap, str);
	while (*format != '\0')
	{
		if (*str == '%')
		{
			count += dispatch_flags(&str, ap);
			str++;
		}
		else
			count += dispatch_normal(&str);
	}
	va_end(ap);
	return (count);
}
