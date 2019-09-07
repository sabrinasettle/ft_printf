/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_upper_hex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 12:34:06 by ssettle           #+#    #+#             */
/*   Updated: 2019/09/07 12:12:33 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*prec_u_hex(t_opts options, char *str)
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
			new_str = pf_append(new_str, "0X", 0);
    }
	free(str);
	return(new_str);
}


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

char *print_reg_X(t_opts options, char *str)
{
	char *new_str;
	
	if (!options.precision && !options.width_field && options.flags.pound)
		new_str = pf_strjoin("0X", str);
	else 
		return(str);
	free(str);
	return(new_str);
}

// itoa is not correct because of it doesnt do the uppercase
int			convert_upper_hex(t_opts options, va_list ap)
{
	char		*str;
	int			len;
	
	str = pf_itoa_upper_hex(options.content_size == 'l' || options.content_size == 'l' + 'l' ?
		(va_arg(ap, uint64_t)) : (va_arg(ap, uint32_t)));
	len = pf_strlen(str);
	if (options.precision > len)
		str = prec_u_hex(options, str);
	if (options.width_field > len)
	{
		str = padding_upper_hex(options, str);
		if (options.flags.pound >= 1)
			str = pf_append(str, "0X", 0);
	}
	str = print_reg_X(options, str);
	pf_putstr(str);
	len = pf_strlen(str);
	free(str);
	return(len);
}
