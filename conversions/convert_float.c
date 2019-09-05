/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 10:53:40 by ssettle           #+#    #+#             */
/*   Updated: 2019/09/05 13:33:32 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// from forum https://github.com/Fulguritude/42_ft_printf/blob/master/handler_utils_float.c
// https://github.com/Fulguritude/42_ft_printf/blob/master/handler_utils_float_prec.c

/*
** You have to manage the following conversion: f with the following flags : l and L
*/

//DOES TAKE THE SPACE FLAG

// long double     content_sizing(t_opts options, va_list ap)
// {
//     double c;
    
// 	if (options.content_size == 0)
// 		c = va_arg(ap, double);
// 	else if (options.content_size == 108) //does not work
// 
// }

// long double			get_float_number(va_list *ap, t_s fs)
// {
// 	if (fs.length == L_LENGTH)
// 		return ((long double)va_arg(*ap, long double));
// 	if (fs.length == l_LENGTH)
// 		return ((double)va_arg(*ap, double));
// 	else
// 		return ((float)va_arg(*ap, double));
// }

// int					f_print(va_list *ap, t_s fs)
// {
// 	long double	f;
// 	int			len;

// 	f = get_float_number(ap, fs);
// 	if (!fs.prec)
// 		fs.prec = fs.dot ? 0 : 6;
// 	fs.dot = (fs.prec || fs.hash);
// 	len = ft_numlen(ABS((int)f), 10) +
// 		fs.dot + fs.prec + is_sign(f < 0, fs);
// 	if (!fs.minus && fs.zero)
// 	{
// 		sign_handler(f < 0, fs);
// 		ft_make_width(fs.width - len, '0');
// 	}
// 	(!fs.minus && !fs.zero) ? ft_make_width(fs.width - len, ' ') : 0;
// 	ft_put_float(f, fs);
// 	fs.minus ? ft_make_width(fs.width - len, ' ') : 0;
// 	return (get_big(len, fs.width));
// }


int		convert_float(t_opts options, va_list ap)
{
    char    *str;
    char    *new_str;
    int len;
    long double num;
      
    (void)new_str;
    (void)options;
    (void)num;
    // (options.content_size > 0) ? num = content_sizing(options, ap): (va_arg(ap, double));
    str = pf_itoa(va_arg(ap, double));
	if (options.flags.space == 1)
		str = pf_append(str, " ", 0);
    pf_putstr(str);
    len = pf_strlen(str);
    free(str);
    return(len);
}
