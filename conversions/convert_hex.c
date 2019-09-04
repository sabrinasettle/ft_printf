/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 12:33:39 by ssettle           #+#    #+#             */
/*   Updated: 2019/09/04 13:51:14 by ssettle          ###   ########.fr       */
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

char		*prec_hex(t_opts options, char *str)
{
	char *new_str;
	int len;

	new_str = pf_strdup(str);
	len = pf_strlen(str);
	if (options.precision > len)
		new_str = pf_memset(new_str, '0', (options.precision - len));
	if (options.flags.pound != 0)
	{
		str = pf_strjoin("0x", str);
		new_str = pf_append(str, new_str, 2);
	}
	else 
		new_str = pf_strjoin(new_str, str);
	return(new_str);
}

char		*padding_hex(t_opts options, char *str)
{
	int wd_len;
	int len;
	int new_len;
	char *new_str;

	new_len = 0;
	len = pf_strlen(str);
	wd_len = options.width_field;
	new_str = pf_strdup(str);
	pf_memset(new_str, ' ', wd_len);
	new_str[wd_len] = '\0';
	if (options.flags.zero >= 1)
	{
		(void)options.flags.minus;	
		if (options.flags.pound >= 1)
		{
			wd_len -= 2;
			pf_memset(new_str, '0', wd_len);
		}
		pf_memset(new_str, '0', wd_len);
	}
	if (options.flags.minus >= 1)
		pf_strncpy(new_str, str, len);
	else
		new_len = wd_len - len;
		pf_strncpy(&new_str[new_len], str, len);
	return(new_str);
}

char *print_reg(t_opts options, char *str)
{
	char *new_str;
	
	if (options.precision == 0 && options.width_field == 0 && options.flags.pound != 0)
		new_str = pf_strjoin("0x", str);
	else 
		return(str);
	return(new_str);
}

int			convert_hex(t_opts options, va_list ap)
{
	char		*str;
	int			len;
	// char		*new_str;
	
	// just need to have a regular 0x and its done
	
	// options.content_size > 0 ? content_sizing(options, ap) : pf_itoa_hex(va_arg(ap, int));
	str = pf_itoa_hex(va_arg(ap, int)); //abs?
	len = pf_strlen(str);
	if (options.precision > len)
		str = prec_hex(options, str);
	if (options.width_field > len)
	{
		str = padding_hex(options, str);
		if (options.flags.pound >= 1)
			str = pf_strjoin("0x", str);
	}
	str = print_reg(options, str);
	pf_putstr(str);
	len = pf_strlen(str);
	free(str);
	return(len);
}

















































































// https://github.com/spitox/ft_printf/blob/master/srcs/print_x.c
// https://github.com/cbg119/42-ft_printf/blob/master/conversions/convert_x.c
// https://github.com/spitox/ft_printf/blob/master/padding/print_x_option.c
// https://github.com/MagicHatJo/-42-ft_printf/blob/master/type/d_x.c