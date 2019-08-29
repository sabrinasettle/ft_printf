/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 12:33:52 by ssettle           #+#    #+#             */
/*   Updated: 2019/08/28 17:37:02 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			convert_pointer(t_opts options, va_list ap)
{
	char *str;
    char *new_str;
    int len;
    (void)options;
    
    str = pf_itoa_p(va_arg(ap, intptr_t));
    new_str = pf_strjoin("0x", str);
    len = pf_strlen(new_str);
    pf_putstr(new_str);
    free(new_str);
    free(str);
    return(len);
}
