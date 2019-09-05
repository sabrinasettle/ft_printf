/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 12:33:39 by ssettle           #+#    #+#             */
/*   Updated: 2019/09/05 15:20:44 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*prec_hex(t_opts options, char *str)
{
	char *new_str;
	int len;
    int z_len;
	int new_len;

	new_str = pf_strdup(str);
	len = pf_strlen(str);
    z_len = options.precision;
	new_str[z_len] = '\0';
	if (options.precision > len)
    {
		pf_memset(new_str, '0', z_len);
		new_len = z_len - len;
        pf_strncpy(&new_str[new_len], str, len);
		if (options.flags.pound != 0)
			new_str = pf_append(new_str, "0x", 0);
    }
	free(str);
	return(new_str);
}

char		*padding_hex(t_opts options, char *str) //is 28 lines :(
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
	free(str);
	return(new_str);
}

char *print_reg(t_opts options, char *str)
{
	char *new_str;
	
	if (!options.precision && !options.width_field && options.flags.pound)
		new_str = pf_strjoin("0x", str);
	else 
		return(str);
	free(str);
	return(new_str);
}

int			convert_hex(t_opts options, va_list ap)
{
	char		*str;
	int			len;
	
	str = options.content_size == 'l' || options.content_size == 'l' + 'l' ?
		pf_itoa_hex(va_arg(ap, uint64_t)) : pf_itoa_hex(va_arg(ap, uint32_t));
	len = pf_strlen(str);
	if (options.precision > len)
		str = prec_hex(options, str);
	if (options.width_field > len)
	{
		str = padding_hex(options, str);
		if (options.flags.pound >= 1)
			str = pf_append(str, "0x", 0);
	}
	str = print_reg(options, str);
	pf_putstr(str);
	len = pf_strlen(str);
	free(str);
	return(len);
}
