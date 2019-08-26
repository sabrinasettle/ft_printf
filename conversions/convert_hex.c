/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 12:33:39 by ssettle           #+#    #+#             */
/*   Updated: 2019/08/26 10:00:37 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// int     content_sizing(t_opts options, va_list ap)
// {
//     char c;
    
// 	if (options.content_size == 0)
// 		c = va_arg(ap, unsigned int);
// 	else if (options.content_size == 108) //does not work
// 		c = va_arg(ap, unsigned long int);
//     else if (options.content_size == 104) //does not work
// 		c = va_arg(ap, unsigned short int);
//     else if (options.content_size == 216) //does not work
// 		c = va_arg(ap, unsigned long long int);
// 	else if (options.content_size == 208) //does not work
// 		c = va_arg(ap, unsigned char); //same as signed char
// 	else if (options.content_size == 106) //does not work
// 		c = va_arg(ap, uintmax_t);
// 	else if (options.content_size == 122) //does not work
// 		c = va_arg(ap, size_t);
//     return(c);
// }

int		convert_hex(t_opts options, va_list ap)
{
	char		*str;
	int			len;
	// char		*new_str;
	(void)options;

	// if (options.content_size > 0)
		// str = content_sizing(options, ap);
	str = pf_itoa_hex(va_arg(ap, int)); //abs?
	len = pf_strlen(str);
	// if (options.width_field > len)
	// {
	// 	new_str = padding_nbr(options, str);
	// 	pf_putstr(new_str);
	// 	free(new_str);
	// }
	
	// else 
		pf_putstr(str);
	len = pf_strlen(str);
	free(str);
	return(len);

}


















































































// https://github.com/spitox/ft_printf/blob/master/srcs/print_x.c
// https://github.com/cbg119/42-ft_printf/blob/master/conversions/convert_x.c
// https://github.com/spitox/ft_printf/blob/master/padding/print_x_option.c
// https://github.com/MagicHatJo/-42-ft_printf/blob/master/type/d_x.c