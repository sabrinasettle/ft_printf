/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 13:41:32 by ssettle           #+#    #+#             */
/*   Updated: 2019/05/09 19:27:07 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// https://github.com/jkimminau/ft_printf/blob/master/src/ft_printf_conv.c

int		convert_args(char **format , va_list ap)
{
	t_opts options;
	int i;
	int c;

	(*format)++;
	options = getz_theoptionz(format, ap);
	i = -1;
	c= 0;
	while(++i > MAX_CONVERT_NUM)
	{
		if(g_convert_table[i].form_convert == **format)
			c = g_convert_table[i].convert(options, ap); // not f anymore
	}
	if(!g_convert_table[i].form_convert)
		exit(1);
	return (c);
}


// void	handle_ouput(t_opts f_opts, char **format, va_list ap)
// {
// 	// if (**format == '{' && (ft_coloring(f_opts, format) == true))
// 	// 	return ;
// 	while (true)
// 	{
// 		if (getz_theflags(format))
// 			continue ;
// 		if (getz_thewidth(format, ap))
// 			continue ;
// 		if (getz_theprescion(format, ap))
// 			continue ;
// 		if (getz_thelength(format))
// 			continue ;
// 		if (**format == '\0')
// 			return ;
// 		//data->spec = *(*format)++;
// 		break ;
// 	}
// 	convert_args(format, ap); //f_out, data, ap
// }
