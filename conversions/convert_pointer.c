/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 12:33:52 by ssettle           #+#    #+#             */
/*   Updated: 2019/09/08 13:52:41 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*padding_point(t_opts options, char *str)
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

int			convert_pointer(t_opts options, va_list ap)
{
	char	*str;
	int		len;

	str = pf_itoa_p(va_arg(ap, intptr_t));
	str = pf_append(str, "0x", 0);
	len = pf_strlen(str);
	if (options.width_field > len)
		str = padding_point(options, str);
	pf_putstr(str);
	free(str);
	return (len);
}
