/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 12:33:59 by ssettle           #+#    #+#             */
/*   Updated: 2019/08/16 13:17:47 by ssettle          ###   ########.fr       */
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


char	*str_prec(t_opts options, char *str)
{
	int32_t		len;
	char 		*new_str;

	len = options.precision;
	(void)options.flags.minus;
	new_str = pf_strsub(str, 0, len);
	return(new_str);
	// free(new_str);
}

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
		new_len = wd_len - len;
		pf_strncpy(&new_str[new_len], str, len);
	return(new_str);
	// free(str);
}

int		convert_str(t_opts options, va_list ap)
{
	int32_t		len;
	char		*new_str;
	char		*str;
	
	str = (char *)va_arg(ap, char *);
	// if (options.content_size > 0)
	// 	str = change_data_type(options, ap);
	// printf("content size: %d", options.content_size); //testing
	
	len = pf_strlen(str);
	if (options.width_field > len)
	{
		new_str = padding_str(options, str);
		if (options.precision <= len && options.precision)
			new_str = padding_str(options, str_prec(options, str));
		pf_putstr(new_str);
	}
	else if (options.precision <= len && options.precision)
	{
		new_str = str_prec(options, str);
		pf_putstr(new_str);
		free(new_str);
		// free(str);
	}
	else 
		pf_putstr(str);
	len = pf_strlen(str);
	// free(new_string); proably will need this
	// free (str);
	return (len);
}

//praticce with strsub









































































// static int parse(t_opts options, int j, char *str)
// {
// 	int 	i;
// 	t_flags flags;

// 	i = 0;
// 	j = 0;
// 	while (options.field_width && options.field_width - i > j && !(flags.minus))
// 	{
// 		pf_putchar(flags.zero ? '0' : ' '); //dont remeber this but its smart
// 		i++;
// 	}
// 	if ((int)ft_strlen(str) > options.field_width && options.precision != -1)
// 	{
// 		while (j < options.precision && str[j])
// 		{
// 			ft_putchar(str[j]);
// 			i++;
// 			j++;
// 		}
// 	}
// 	else
// 		i += (int)write(1, str, ft_strlen((char *)str));
// 	return (i);

// }

// //will need to put null terminator at the end of the string as usual
// int			convert_str(t_opts options, va_list ap)
// {
// 	char	*s;
// 	int		i;
// 	int		j;
// 	t_flags	flags;

// 	i = 0;
// 	s = va_arg(ap, char *);
// 	{
// 		free(s);
// 		s = "(null)";
// 	}
// 	if (options.precision == -1)
// 		options.precision = 0;
// 	else if (options.precision == 0)
// 		options.precision = -1;
// 	j = ((int)ft_strlen(s) > options.precision && options.precision != -1) ?
// 		options.precision : (int)ft_strlen(s);
// 	i += parse(options, j, s);
// 	while (options.field_width && options.width > j && flags.minus)
// 	{
// 		ft_putchar(' ');
// 		options.field_width--;
// 		i++;
// 	}
// 	return (i);
// }
























// https://github.com/spitox/ft_printf/blob/master/srcs/print_s.c
// https://github.com/NicoGGG/ft_printf.2/blob/master/src/ft_putstr.c
// https://github.com/MagicHatJo/-42-ft_printf/blob/master/type/d_s.c
// https://github.com/cbg119/42-ft_printf/blob/master/conversions/convert_s.c