/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:59:31 by ssettle           #+#    #+#             */
/*   Updated: 2019/09/09 12:47:27 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** A % followed by another % character will write a single % to the stream.
** Works only with width.
*/

char	*padding_per(t_opts options, char *str)
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

int		convert_percent(t_opts options, va_list ap)
{
	int		len;
	char	*str;

	(void)ap;
	str = "%";
	len = pf_strlen(str);
	if (options.width_field > len)
		str = padding_per(options, str);
	len = pf_strlen(str);
	pf_putstr(str);
	return (len);
}
