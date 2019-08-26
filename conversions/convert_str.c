/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 12:33:59 by ssettle           #+#    #+#             */
/*   Updated: 2019/08/26 14:43:39 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** The only flag for str is l which creates a wchar_t.
*/

// if (pf_strcmp(tab->argument_flag, "l") == 0)
// 		c = (unsigned long)va_arg(tab->args, unsigned long);
// 	else if (tab->specifier_flag == 'C')
// 		c = (wchar_t)va_arg(tab->args, wint_t);
// why did he cast as such????


// char		change_data_type(t_opts options, va_list ap)
// {
// 	char *c;
// 	c = (char *)va_arg(ap, char *);
// 	if (options.content_size > 0)
// 		c = (wchar_t)va_arg(ap, wchar_t);
// 	return(&c); //return is wrong for the function
// }


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
	return(new_str);
}

char	*str_prec(t_opts options, char *str)
{
	int32_t		len;
	// char 		*new_str;

	len = options.precision;
	(void)options.flags.minus;
	// new_str = pf_strsub(str, 0, len); //malloc
	return(pf_strsub(str, 0, len));
}

void	padding_and_prec(t_opts options, char *str)
{
	char *p_str;
	char *new_str2;
	
	p_str = str_prec(options, str);
	new_str2 = padding_str(options, p_str);
	pf_putstr(new_str2);
	free(p_str);
	free(new_str2);
}

int		convert_str(t_opts options, va_list ap)
{
	int32_t		len;
	char		*new_str;
	char		*str;
	
	str = (char *)va_arg(ap, char *);
	// if (options.content_size > 0) //dont need???
		// str = change_data_type(options, ap);
	len = pf_strlen(str);
	if (options.width_field > len)
	{
		new_str = padding_str(options, str);
		(options.precision <= len && options.precision) ? 
			padding_and_prec(options, str) : pf_putstr(new_str);
		free(new_str);
	}
	else if (options.precision <= len && options.precision)
	{
		new_str = str_prec(options, str);
		pf_putstr(new_str);
		free(new_str);
	}
	else 
		pf_putstr(str);
	len = pf_strlen(str);
	return (len);
}
// printf("content size: %d", options.content_size); //testing
































































































// https://github.com/spitox/ft_printf/blob/master/srcs/print_s.c
// https://github.com/NicoGGG/ft_printf.2/blob/master/src/ft_putstr.c
// https://github.com/MagicHatJo/-42-ft_printf/blob/master/type/d_s.c
// https://github.com/cbg119/42-ft_printf/blob/master/conversions/convert_s.c