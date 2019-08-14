/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 12:33:59 by ssettle           #+#    #+#             */
/*   Updated: 2019/08/13 14:11:00 by ssettle          ###   ########.fr       */
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


// if minus is is true then padd on the right
// int		padding_str(t_opts options)
// {
// 	while (options.width_field != 0 && options.flags.minus)
// 	{
		
// 	}

// }
// if presicion exists (.) then the len designated from that is applied to the str. so 5 on abcdefg becomes abcde


// Sam says to see if there is prec and len gets set by the default of the prec. 
//Oterwise you allowed the entire str, ft_strsub
int		convert_str(t_opts options, va_list ap)
{
	int		len;
	int		new_len;
	char	*new_str;
	char	*str;
	int		i;
	
	len = 0; //testing
	str = (char *)va_arg(ap, char *);
	i = 0;
	// if (options.content_size > 0)
	// 	str = change_data_type(options, ap);
	// printf("content size: %d", options.content_size); //testing
	
	// printf("presion size: %d\n", options.precision); //comes back correct
	len = pf_strlen(str);
	// printf("str len: %d\n", len);
	// printf("length1:%d\n", options.width_field);
	new_len = options.width_field;
	// printf("new_len: %d", new_len);
	while (new_len > 1)
	{
		new_len--;
		pf_putchar(' ');
	}
	// new_len = options.width_field - len;
	// printf("new_len: %d", new_len);
	while (new_len > 1 && options.flags.minus)
	{
		new_len--;
		// options.width_field--;
		pf_putchar(' ');
		// len++;
	}
	if (options.precision <= len && options.precision)
	{
		len = options.precision;
		// printf("new_len: %d\n", new_len);
		(void)options.flags.minus;
		new_str = pf_strsub(str, 0, len);
		pf_putstr(new_str);
	}
	
	// printf("length:%d\n", options.width_field);

	//strjoin subract the len from the width ELIIII
	
	


	else
		pf_putstr(str);
	// free(new_string); proably will need this
	// free (str);
	// printf("new_len: %d\n", new_len);
	// printf("\nlen: %d\n", len);
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