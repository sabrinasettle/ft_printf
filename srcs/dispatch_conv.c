/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 13:41:32 by ssettle           #+#    #+#             */
/*   Updated: 2019/07/22 13:36:50 by ssettle          ###   ########.fr       */
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

int		convert_args(const char **format , va_list ap)
{
	t_opts options;
	int i;
	int c;

	// format++;
	options = getz_theoptionz(*format, ap);
	i = 0;
	c = 0;
	// while of some sort
	if(g_convert_table[i].form_convert)
		c = g_convert_table[i].convert(options, ap);
	if(!g_convert_table[i].form_convert)
	{
		write(1, "exiting\n", 8); //says putstr?
		exit(1);
	}
	return (c);
}

// int		convert_args(const char **format , va_list ap)
// {
	// return(0);
// }







// table access by andy

// void	ft_formatting(char **s, va_list *ap, int *res)
// {
// 	t_s		fs;
// 	int		format;
// 	int		len;

// 	len = 0;
// 	flag_setting(&fs);
// 	format = get_format(s, &format, &fs);
// 	if (fs.w_star || fs.p_star)
// 		star_handler(ap, &fs);
// 	if (g_dt[format].specifier)
// 		len = g_dt[format].function(ap, fs);
// 	*res += len > 0 ? len : 0;
// 	*s += 1;
// }







// chris ford


// int		ft_printf_dispatch(t_format variable, int fd)
// {
// 	int		size;
// 	int		i;

// 	size = 0;
// 	i = 0;
// 	while (i < 10)
// 	{
// 		if (g_table[i].c & variable.spec)
// 		{
// 			size = g_table[i].function(variable, fd);
// 			break ;
// 		}
// 		i++;
// 	}
// 	return (size);
// }



// int			convert_args(const char **format, va_list ap)
// {
// 	int		i;
// 	t_flag	flag;

// 	i = 0;
// 	flag = get_flags(format);
// 	while (g_conv[i].format_conv && g_conv[i].format_conv != **format)
// 		i++;
// 	if (!g_conv[i].format_conv)
// 		exit(1);
// 	return (g_conv[i].f(ap, flag));
// }































// https://github.com/NicoGGG/ft_printf.2/blob/master/src/convert_args.c
// https://github.com/cbg119/42-ft_printf/blob/master/src/ft_printf.c
