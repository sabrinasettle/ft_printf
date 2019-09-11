/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 13:41:32 by ssettle           #+#    #+#             */
/*   Updated: 2019/09/11 15:19:14 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Converts the the flags arguements. options are equal to those set up in the
** get_optionz function. It then accesses the dispatch table and it varible
** arguments of char and t_conv(t_opts, va_list). This is the inner parse to
** the ft_printf call and then speaks to the dispatch table to rereoute the
** conversion.
*/

int		convert_args(const char **format, va_list ap)
{
	t_opts	options;
	int		i;
	int		c;

	options = getz_theoptionz(format, ap);
	i = -1;
	c = 0;
	while(++i < 13)
	{
		if (g_convert_table[i].form_convert == **format)
			c = g_convert_table[i].convert(options, ap);
		if(!(g_convert_table[i].form_convert))
		{
			write(1, "exiting\n", 8);
			exit(1);
		}
	}
	return (c);
}
