/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 12:33:59 by ssettle           #+#    #+#             */
/*   Updated: 2019/09/09 10:30:09 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

//no space flag

/*
** The only flag for str is l which creates a wchar_t.
*/

char		*padding_str(t_opts options, char *str)
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
	if (options.flags.minus >= 1)
		pf_strncpy(new_str, str, len);
	else
	{
		new_len = wd_len - len;
		pf_strncpy(&new_str[new_len], str, len);
	}
	free(str);
	return(new_str);
}

char		*prec_str(t_opts options, char *str)
{
	char	*new_str;

	new_str = pf_strsub(str, 0, options.precision);
	free(str);
	return(new_str);
}

int		convert_str(t_opts options, va_list ap)
{
	int32_t		len;
	char		*new_str;
	char		*str;
	(void)options;
	
	str = (char *)va_arg(ap, char *);
	if (!str)
		str = "(null)";
	new_str = pf_strdup(str);
	len = pf_strlen(new_str);
	if (options.precision <= len && options.precision)
		new_str = prec_str(options, new_str);
	if (options.width_field > len)
		new_str = padding_str(options, new_str); //leakinggggggg
	pf_putstr(new_str);
	len = pf_strlen(new_str);
	free(new_str);
	return (len);
}
// printf("content size: %d", options.content_size); //testing
































































































// https://github.com/spitox/ft_printf/blob/master/srcs/print_s.c
// https://github.com/NicoGGG/ft_printf.2/blob/master/src/ft_putstr.c
// https://github.com/MagicHatJo/-42-ft_printf/blob/master/type/d_s.c
// https://github.com/cbg119/42-ft_printf/blob/master/conversions/convert_s.c