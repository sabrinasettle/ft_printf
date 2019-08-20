/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 12:33:39 by ssettle           #+#    #+#             */
/*   Updated: 2019/07/30 18:37:53 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// https://github.com/spitox/ft_printf/blob/master/srcs/print_x.c
// https://github.com/cbg119/42-ft_printf/blob/master/conversions/convert_x.c
// https://github.com/spitox/ft_printf/blob/master/padding/print_x_option.c
// https://github.com/MagicHatJo/-42-ft_printf/blob/master/type/d_x.c

int     content_sizing(t_opts options, va_list ap)
{
    char c;
    
	if (options.content_size == 0)
		c = va_arg(ap, unsigned int);
	else if (options.content_size == 108) //does not work
		c = va_arg(ap, unsigned long int);
    else if (options.content_size == 104) //does not work
		c = va_arg(ap, unsigned short int);
    else if (options.content_size == 216) //does not work
		c = va_arg(ap, unsigned long long int);
	else if (options.content_size == 208) //does not work
		c = va_arg(ap, unsigned char); //same as signed char
	else if (options.content_size == 106) //does not work
		c = va_arg(ap, uintmax_t);
	else if (options.content_size == 122) //does not work
		c = va_arg(ap, size_t);
    return(c);
}

int		convert_hex(t_opts f_opts, va_list ap)
{
	int	len;
	unsigned int num;

	len = 0;
	num = va_arg(ap, unsigned int);
	// len = 


}
