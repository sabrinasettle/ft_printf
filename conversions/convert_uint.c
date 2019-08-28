/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 12:34:04 by ssettle           #+#    #+#             */
/*   Updated: 2019/08/28 15:21:10 by ssettle          ###   ########.fr       */
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

char		*padding_unbr(t_opts options, char *str)
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
		pf_memset(new_str, '0', wd_len);	
	}
	if (options.flags.minus >= 1)
		pf_strncpy(new_str, str, len);
	else
		new_len = wd_len - len;
		pf_strncpy(&new_str[new_len], str, len);
	return(new_str);
}

int				convert_uint(t_opts options, va_list ap)
{
    char *str;
    char *new_str;
    int len;
    
	str = pf_itoa(va_arg(ap, uint32_t));
    len = pf_strlen(str);
    if (options.precision > len)
		write(1, "0", ((options.precision - len) + 1));
	if (options.width_field > len)
	{
		new_str = padding_unbr(options, str);
		pf_putstr(new_str);
		free(new_str);
	}
	else 
        pf_putstr(str);
    free(str);
    return((uint64_t)len);
}
