/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 19:37:27 by ssettle           #+#    #+#             */
/*   Updated: 2019/05/07 15:52:21 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	conv_percent(t_flags *flags) //or (t_opts f_opts, va_list ap)
{
	char *res;
	int len;

	res = ft_strdup("%");
	if (res)
		res =

	// (void)opts;
	// (void)ap;
	//ft_putchar('%');
	//return (0);
}

int	convert(t_flags *flags, char **str, va_list *ap)
{

	if (*str == '%')
	{
		return (conv_percent(flags)); //conv perc???
		if (*(++str) == 0)
			break ;
		handle_output(&f_out, &format, ap);
	}
}



// if (*format == '%')
// 		{
// 			if (*(++format) == 0)
// 				break ;
// 			ft_handle(&f_out, &format, ap);
// 		}
