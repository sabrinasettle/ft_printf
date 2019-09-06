/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 12:33:59 by ssettle           #+#    #+#             */
/*   Updated: 2019/09/06 14:04:11 by ssettle          ###   ########.fr       */
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
	len = pf_strlen(str); // no malloc
	wd_len = options.width_field;
	new_str = pf_strdup(str); //malloc
	pf_memset(new_str, ' ', wd_len); //no malloc
	new_str[wd_len] = '\0';
	if (options.flags.minus >= 1)
		pf_strncpy(new_str, str, len); //no malloc
	else
	{
		new_len = wd_len - len;
		pf_strncpy(&new_str[new_len], str, len); //no malloc
	}
	// free(str); //doesnt work and breaks
	return(new_str);
}


//print (nil) needed

int		convert_str(t_opts options, va_list ap)
{
	int32_t		len;
	// char		*new_str;
	char		*str;
	
	// if (options.content_size > 0) //dont need???
		// str = change_data_type(options, ap);
	str = (char *)va_arg(ap, char *);
	len = pf_strlen(str);
	//if strcmp is == 1 when given NULL print  str = (null)
	if (options.precision <= len && options.precision)
		str = pf_strsub(str, 0, options.precision);
	if (options.width_field > len)
		str = padding_str(options, str); //leakinggggggg
	pf_putstr(str);
	len = pf_strlen(str);
	// free(str);
	return (len);
}
// printf("content size: %d", options.content_size); //testing
































































































// https://github.com/spitox/ft_printf/blob/master/srcs/print_s.c
// https://github.com/NicoGGG/ft_printf.2/blob/master/src/ft_putstr.c
// https://github.com/MagicHatJo/-42-ft_printf/blob/master/type/d_s.c
// https://github.com/cbg119/42-ft_printf/blob/master/conversions/convert_s.c