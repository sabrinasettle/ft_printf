/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 12:33:52 by ssettle           #+#    #+#             */
/*   Updated: 2019/08/28 09:50:52 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			convert_pointer(t_opts options, va_list ap)
{
	char *str;
    int len;
    (void)options;
    
    str = pf_itoa_hex(va_arg(ap, intptr_t));
    //do options here
    pf_putstr(str);
    len = pf_strlen(str);
    free(str);
    return(len);
}
