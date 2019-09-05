/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 12:33:52 by ssettle           #+#    #+#             */
/*   Updated: 2019/09/05 13:03:01 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// no hash no plus, but spaces if width is defined and - as well
// The address of a is: (nil) ==== %p 0

//no space flag

char		*padding_point(t_opts options, char *str)
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
		new_len = wd_len - len;
		pf_strncpy(&new_str[new_len], str, len);
	return(new_str);
}

int			convert_pointer(t_opts options, va_list ap)
{
	char *str;
    char *new_str;
    int len;
    (void)options;
    
    str = pf_itoa_p(va_arg(ap, intptr_t));
    new_str = pf_strjoin("0x", str);
     len = pf_strlen(new_str);
    if (options.width_field > len)
        new_str = padding_point(options, new_str);
    len = pf_strlen(new_str);
    pf_putstr(new_str);
    free(new_str);
    free(str);
    return(len);
}
