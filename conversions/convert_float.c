/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 10:53:40 by ssettle           #+#    #+#             */
/*   Updated: 2019/08/28 18:07:44 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// from forum https://github.com/Fulguritude/42_ft_printf/blob/master/handler_utils_float.c
// https://github.com/Fulguritude/42_ft_printf/blob/master/handler_utils_float_prec.c

/*
** You have to manage the following conversion: f with the following flags : l and L
*/

// int     content_sizing(t_opts options, va_list ap)
// {
//     char c;
    
// 	if (options.content_size == 0)
// 		c = va_arg(ap, unsigned int);
// 	else if (options.content_size == 108) //does not work
// 
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
    // if (options.content_size > 0)
		// num = content_sizing(options, ap);
    str = pf_itoa(va_arg(ap, double));
    pf_putstr(str);
    len = pf_strlen(str);
    free(str);
    return(len);
}
