/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_upper_hex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 12:34:06 by ssettle           #+#    #+#             */
/*   Updated: 2019/08/27 18:53:37 by ssettle          ###   ########.fr       */
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

char		*padding_upper_hex(t_opts options, char *str)
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
			pf_putstr("0x");
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

int				convert_upper_hex(t_opts options, va_list ap)
{
	char		*str;
	int			len;
	char		*new_str;
	
	// if (options.content_size > 0)
		// str = content_sizing(options, ap);
	str = pf_itoa_hex(va_arg(ap, int)); //abs?
	len = pf_strlen(str);
	if (options.width_field > len)
	{
		new_str = padding_upper_hex(options, str);
		pf_putstr(new_str);
		free(new_str);
	}
	else 
		pf_putstr(str);
	len = pf_strlen(str);
	free(str);
	return(len);
}
