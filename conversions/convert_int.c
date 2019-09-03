/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 12:33:44 by ssettle           #+#    #+#             */
/*   Updated: 2019/09/03 14:26:30 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Conversion for i and d. Really only has a difference if you are using scanf.
*/

char    *pf_append_int(char *subject, char *insert, int pos) // never used
{
    char    *new_str;
    char    *buf;
    int     len;
    
    buf = pf_strnew(pf_strlen(subject));
    pf_strncpy(buf, subject, pos); 
    len = strlen(buf);
    pf_strcpy(buf + len, insert);
    len += pf_strlen(insert);
    pf_strcpy(buf + len, subject + pos);
    new_str = pf_strcpy(subject, buf);
    free(buf);
    return(new_str);
}

char    *padding_nbr(t_opts options, char *str)
{
    int     wd_len;
    int     len;
    int     new_len;
    char    *new_str;
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

int     convert_int(t_opts options, va_list ap)
{
    char        *str;
    int         len;
    char        *new_str;
    
    str = options.content_size > 0 ? 
        pf_itoa_base_l(va_arg(ap, int64_t)) : pf_itoa(va_arg(ap, int32_t));
    len = pf_strlen(str);
    if (options.precision > len) //??
        write(1, "0", ((options.precision - len) + 1)); //strjoin
        // new_str = pf_strjoin("0x", str);
    if (options.flags.plus == 1)
        pf_append(str, "+", 0);
    if (options.width_field > len)
    {
        new_str = padding_nbr(options, str);
        pf_putstr(new_str);
        free(new_str);
    }
    else
        pf_putstr(str);
    len = pf_strlen(str);
    free(str);
    return(len);
}