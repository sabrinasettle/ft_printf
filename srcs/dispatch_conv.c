/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 13:41:32 by ssettle           #+#    #+#             */
/*   Updated: 2019/07/17 17:13:47 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// https://github.com/NicoGGG/ft_printf.2/blob/master/src/convert_args.c
// https://github.com/cbg119/42-ft_printf/blob/master/src/ft_printf.c

/*
** Converts the the flags arguements. options are equal to those set up in the
** get_optionz function. It then accesses the dispatch table and it varible
** arguments of char and t_conv(t_opts, va_list).
*/

// int		convert_args(const char **format , va_list ap)
// {
// 	t_opts options;
// 	int i;
// 	int c;

// 	(*format)++;
// 	options = getz_theoptionz(&format, ap);
// 	i = -1;
// 	c= 0;
// 	while(++i < MAX_CONVERT_NUM)
// 	{
// 		if(g_convert_table[i].form_convert == *format)
// 			c = g_convert_table[i].convert(options, ap);
// 	}
// 	if(!g_convert_table[i].form_convert)
// 		exit(1);
// 	return (c);
// }

int		convert_args(const char **format , va_list ap)
{
	return(0);
}