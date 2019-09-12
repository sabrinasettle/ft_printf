/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 12:33:39 by ssettle           #+#    #+#             */
/*   Updated: 2019/09/11 16:14:54 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*prec_hex(t_opts options, char *str)
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
		if (options.flags.pound != 0)
			new_str = pf_append(new_str, "0x", 0);
	}
	free(str);
	return (new_str);
}

char		*padding_hex(t_opts options, char *str)
{
	int		wd_len;
	int		len;
	int		new_len;
	char	*new_str;

	new_len = 0;
	len = pf_strlen(str);
	wd_len = options.width_field;
	new_str = pf_strdup(str);
	if (options.flags.pound && options.flags.zero)
		wd_len -= 2;
	pf_memset(new_str, ' ', wd_len);
	new_str[wd_len] = '\0';
	if (options.flags.zero && !options.flags.minus)
		pf_memset(new_str, '0', wd_len);
	if (options.flags.minus > 0)
		pf_strncpy(new_str, str, len);
	else
	{
		new_len = wd_len - len;
		pf_strncpy(&new_str[new_len], str, len);
	}
	free(str);
	return (new_str);
}

char		*print_reg(t_opts options, char *str, int len)
{
	char	*new_str;

	if ((str[len - 1] == 48) && options.flags.dot && !options.precision
		&& options.width_field)
		pf_memset(str, ' ', len);
	if (!options.precision && !options.width_field && !options.flags.zero
		&& options.flags.pound && !(str[0] == 48 && str[1] == '\0')
		&& !options.flags.dot)
		new_str = pf_strjoin("0x", str);
	else
		return (str);
	free(str);
	return (new_str);
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
		if (options.flags.pound > 0 && options.width_field && !options.flags.dot
			&& !options.flags.zero)
			str = pf_append(str, "0x", 0);
		str = padding_hex(options, str);
		if (options.flags.pound && options.flags.zero && !options.flags.dot)
			str = pf_append(str, "0x", 0);
	}
	str = print_reg(options, str,
		(len = pf_strlen(str)));
	len = (str[0] == 48 && str[1] == '\0') && options.flags.dot
		&& !options.precision ? 0 : pf_putstr_i(str);
	free(str);
	return (len);
}
