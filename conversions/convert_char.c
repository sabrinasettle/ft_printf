/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 10:39:33 by ssettle           #+#    #+#             */
/*   Updated: 2019/07/30 16:04:22 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** 1 width we print only the c, with 2 width we print
** a space AND the c. The only flag for char is l which creates a wint_t.
*/

// still needs to work with l... but padding works



int						add_width_and_convert(t_opts options, va_list ap)
{
	char			c;
	int				length;

	length = 1;
	if (options.content_size == 0)
		c = va_arg(ap, int);
	else if (options.content_size == 108) //does not work
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
	add_width_and_convert(options, ap);
	return (0);
}

// could also use wchar or wint_t due to the unicode and code points

// if (pf_strcmp(tab->argument_flag, "l") == 0)
// 		c = (unsigned long)va_arg(tab->args, unsigned long);
// 	else if (tab->specifier_flag == 'C')
// 		c = (wchar_t)va_arg(tab->args, wint_t);

// *com = ft_strcmp(flags->length, "l") == 0 ?
// 		va_arg(options, wint_t) : va_arg(options, int);