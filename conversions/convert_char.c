/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 10:39:33 by ssettle           #+#    #+#             */
/*   Updated: 2019/07/30 13:10:32 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** 1 width we print only the c, with 2 width we print
** a space AND the c. The only flag for char is l which creates a wint_t.
*/

int						converstion_method(t_opts options, va_list ap)
{
	// t_flags			flags;
	wchar_t			c;
	int				length;

	length = 1;
	c = (unsigned char)va_arg(ap, int);
	while (options.width_field >= 1 && !options.flags.minus)
	{
		pf_putchar(' ');
		options.width_field--;
		length++;
	}
	while (options.width_field >= 1 && options.flags.minus)
	{
		pf_putchar(' ');
		options.width_field--;
		length++;
		// pf_putchar('z'); 
	}
	// (void)options;
	
	write(1, &c, 1);
	return (length);
}

int		convert_char(t_opts options, va_list ap)
{
	converstion_method(options, ap);
	if (options.width_field > 1)
		return (options.width_field);
	return (0);
}

// could also use wchar or wint_t due to the unicode and code points

// if (pf_strcmp(tab->argument_flag, "l") == 0)
// 		c = (unsigned long)va_arg(tab->args, unsigned long);
// 	else if (tab->specifier_flag == 'C')
// 		c = (wchar_t)va_arg(tab->args, wint_t);

// *com = ft_strcmp(flags->length, "l") == 0 ?
// 		va_arg(options, wint_t) : va_arg(options, int);