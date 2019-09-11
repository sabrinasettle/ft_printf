/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_octal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 12:33:46 by ssettle           #+#    #+#             */
/*   Updated: 2019/09/11 13:49:58 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*prec_oct(t_opts options, char *str)
{
	char	*new_str;
	int		len;
    int		z_len;
	int		new_len;

	new_str = pf_strdup(str);
	len = pf_strlen(str);
    z_len = options.precision;
	new_str[z_len] = '\0';
	if (options.precision > len)
    {
		pf_memset(new_str, '0', z_len);
		new_len = z_len - len;
        pf_strncpy(&new_str[new_len], str, len);
    }
	free(str);
	return (new_str);
}

char		*padding_oct(t_opts options, char *str)
{
	int		wd_len;
	int		len;
	int		new_len;
	char	*new_str;

	new_len = 0;
	len = pf_strlen(str);
	wd_len = options.width_field;
	new_str = pf_strdup(str);
	pf_memset(new_str, ' ', wd_len);
	new_str[wd_len] = '\0';
	if (options.flags.zero && !options.flags.minus)
		pf_memset(new_str, '0', wd_len);	
	if (options.flags.minus >= 1)
		pf_strncpy(new_str, str, len);
	else
	{
		new_len = wd_len - len;
		pf_strncpy(&new_str[new_len], str, len);
	}
	free(str);
	return (new_str);
}

char		*print_reg_o(t_opts options, char *str)
{
	char	*new_str;
	
	if (!options.precision && !options.width_field
		&& options.flags.pound && !(str[0] == 48 && str[1] == '\0')
		&& !options.flags.dot)
		new_str = pf_strjoin("0", str);
	else
		return (str);
	free(str);
	return (new_str);
}

int			convert_octal(t_opts options, va_list ap)
{
	char		*str;
	int			len;

	str = pf_itoa_o(options.content_size == 'l' || options.content_size == 216 ?
		(va_arg(ap, uint64_t)) : (va_arg(ap, unsigned long)));
	if (options.precision > (len = pf_strlen(str)))
		str = prec_oct(options, str);
	if (options.width_field > (len = pf_strlen(str)))
	{
		if (options.flags.pound > 0 && options.width_field && !options.flags.dot
			&& !options.flags.zero)
			str = pf_append(str, "0", 0);
		str = padding_oct(options, str);
		if (options.flags.pound && options.flags.zero && !options.flags.dot)
			str = pf_append(str, "0" , 0);
	}
	str = print_reg_o(options, str);
	if ((str[(len = pf_strlen(str)) - 1] == 48) && options.flags.dot 
	&& !options.precision && options.width_field && !options.flags.zero)
		pf_memset(str, ' ', len);
	len = ((str[(len = pf_strlen(str)) - 1] == 48) && options.flags.dot 
	&& !options.precision && !options.flags.pound) ? 0 : pf_putstr_i(str);
	free(str);
	return (len);
}