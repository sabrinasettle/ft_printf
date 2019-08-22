/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 12:33:44 by ssettle           #+#    #+#             */
/*   Updated: 2019/08/22 10:11:38 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Conversion for i and d. Really only has a difference if you are using scanf.
*/

// int		convert_int(t_opts options, va_list ap)
// {
// 	char res;

// 	res = pf_itoa(va_arg(options, int)) //itoa does not exist yet
// 	res = padding(str, options, neg);

// 	pf_putstr(res)
// 	free(res)
// }

// hh = signed char 208 ch
// h = short int 104 ch
// l = long int 108 ch
// ll = long long int 216 ch
// j = intmax_t 106
// z = size_t 122

// int     content_sizing(t_opts options, va_list ap) //instead of options-> int?
// {
//     int64_t c;
    
// 	if (options.content_size == 0)
// 		c = va_arg(ap, int);
// 	else if (options.content_size == 108) //does not work
// 		c = va_arg(ap, long int);
//     else if (options.content_size == 104) //does not work
// 		c = va_arg(ap, short int);
//     else if (options.content_size == 216) //does not work
// 		c = va_arg(ap, long long int);
// 	else if (options.content_size == 208) //does not work
// 		c = va_arg(ap, char); //same as signed char
// 	else if (options.content_size == 106) //does not work
// 		c = va_arg(ap, intmax_t);
// 	else if (options.content_size == 122) //does not work
// 		c = va_arg(ap, size_t);
//     return(c);
// }

// char	*str_prec(t_opts options, char *str)
// {
// 	int32_t		len;
// 	char 		*new_str;

// 	len = options.precision;
// 	(void)options.flags.minus;
// 	new_str = pf_strsub(str, 0, len);
// 	return(new_str);
// 	// free(new_str);
// }

// char		*padding_str(t_opts options, char *str)
// {
// 	int wd_len;
// 	int len;
// 	int new_len;
// 	char *new_str;

// 	new_len = 0;
// 	len = pf_strlen(str);
// 	wd_len = options.width_field;
// 	new_str = pf_strdup(str);
// 	pf_memset(new_str, ' ', wd_len);
// 	new_str[wd_len] = '\0';
// 	if (options.flags.minus >= 1)
// 		pf_strncpy(new_str, str, len);
// 	else
// 		new_len = wd_len - len;
// 		pf_strncpy(&new_str[new_len], str, len);
// 	return(new_str);
// 	// free(str);
// }

// padding with zeros needs to happen as well


int     convert_int(t_opts options, va_list ap)
{
	char		*str;
	int			str_len;
	// int64_t 	n;
	// int			neg;
	(void)options;

	str = pf_itoa(va_arg(ap, int)); //abs?
	
	// if (options.width_field > len)
	// {
	// 	new_str = padding_str(options, str);
	// 	if (options.precision <= len && options.precision)
	// 		new_str = padding_str(options, str_prec(options, str));
	// 	pf_putstr(new_str);
	// }
	// else if (options.precision <= len && options.precision)
	// {
	// 	new_str = str_prec(options, str);
	// 	pf_putstr(new_str);
	// 	free(new_str);
	// 	// free(str);
	// }
	// else 
	pf_putstr(str);
	str_len = pf_strlen(str);
	// free(str);
	return(str_len);

}