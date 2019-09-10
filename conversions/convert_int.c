/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 12:33:44 by ssettle           #+#    #+#             */
/*   Updated: 2019/09/10 16:47:55 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Conversion for i and d. Really only has a difference if you are using scanf.
*/

char	*prec(t_opts options, char *str, int len)
{
	char *new_str;
    int z_len;
	int new_len;

	new_str = pf_strdup(str);
    z_len = options.precision;
	new_str[z_len] = '\0';
	if (options.precision >= len)
    {
		pf_memset(new_str, '0', z_len);
		new_len = z_len - len;
        pf_strncpy(&new_str[new_len], str, len);
    }
	free(str);
	return(new_str);
}

char    *padding_nbr(t_opts options, char *str, int len)
{
    int     wd_len;
    int     new_len;
    char    *new_str;
	
    new_len = 0;
    wd_len = options.width_field;
    new_str = pf_strdup(str);
    pf_memset(new_str, ' ', wd_len);
    new_str[wd_len] = '\0';
    // wd_len = options.flags.plus ? wd_len - 1 : wd_len;
    if (options.flags.zero >= 1)
	{
		// wd_len = options.flags.plus ? wd_len - 1 : wd_len;
        pf_memset(new_str, '0', wd_len);
		new_str[0] = options.flags.plus ? '+': '0';
	}
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

char	*neg_pad_prec(t_opts options, char *str, int len)
{
    char    *new_str;
	
   	new_str = pf_strdup(str);
	new_str[0] = '0';
	// len += 1;
	new_str = padding_nbr(options, new_str, len);
	len = pf_strlen(new_str);
	new_str = prec(options, new_str, len);
	new_str[0] = '-';
	return (new_str);
}

int     convert_int(t_opts options, va_list ap)
{
    char        *str;
	int			is_neg;
    int         len;
    int64_t     num;

    num = options.content_size > 0 ? va_arg(ap, int64_t) : va_arg(ap, int32_t);
	is_neg = (num < 0) ? true : false;
    str = options.content_size > 0 ? pf_itoa_base_l(num) : pf_itoa(num);
	if (options.flags.plus && is_neg == false && !options.flags.zero)
		pf_append(str, "+", 0);
	len = pf_strlen(str);
	if (is_neg == 0)
	{
		if (options.width_field > len)
			str = padding_nbr(options, str, len);
		if (options.precision > (len = pf_strlen(str)))
			str = prec(options, str, len);
		if (options.flags.space && !options.flags.plus)
			str = pf_append(str, " ", 0);
	}
	else
		str = neg_pad_prec(options, str, len);
    len = pf_putstr_i(str);
    free(str);
    return(len);
}