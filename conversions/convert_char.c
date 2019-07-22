/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 10:39:33 by ssettle           #+#    #+#             */
/*   Updated: 2019/07/22 14:29:57 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** 1 width we print only the c, with 2 width we print
** a space AND the c.
*/

int						convert_char(t_opts f_opts, va_list ap)
{
	t_flags			flags;
	wchar_t			c;
	int				length;

	length = 1;
	c = (unsigned char)va_arg(ap, int);
	while (f_opts.field_length > 1 && !flags.minus)
	{
		pf_putchar(' ');
		f_opts.field_length--;
		length++;
	}
	write(1, &c, 1);
	while (f_opts.field_length > 1 && flags.minus)
	{
		pf_putchar(' ');
		f_opts.field_length--;
		length++;
	}
	return (length);
}

// could also use wchar or wint_t due to the unicode and code points

// if (pf_strcmp(tab->argument_flag, "l") == 0)
// 		c = (unsigned long)va_arg(tab->args, unsigned long);
// 	else if (tab->specifier_flag == 'C')
// 		c = (wchar_t)va_arg(tab->args, wint_t);