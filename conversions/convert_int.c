/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 12:33:44 by ssettle           #+#    #+#             */
/*   Updated: 2019/07/30 18:30:19 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Conversion for i and d. Really only has a difference if you are using scanf.
*/

// int		convert_int(t_opts options, va_list ap)
// {
// 	char res;

// 	res = pf_itoa(va_arg(options, int)) //itoa does not exist yet
// 	res = padding(str, options, neg);

// 	pf_putstr(res)
// 	free(res)
// }

// hh = signed char 208 ch
// h = short int 104 ch
// l = long int 108 ch
// ll = long long int 216 ch
// j = intmax_t 106
// z = size_t 122

int     content_sizing(t_opts options, va_list ap) //instead of options-> int?
{
    int64_t c;
    
	if (options.content_size == 0)
		c = va_arg(ap, int);
	else if (options.content_size == 108) //does not work
		c = va_arg(ap, long int);
    else if (options.content_size == 104) //does not work
		c = va_arg(ap, short int);
    else if (options.content_size == 216) //does not work
		c = va_arg(ap, long long int);
	else if (options.content_size == 208) //does not work
		c = va_arg(ap, char); //same as signed char
	else if (options.content_size == 106) //does not work
		c = va_arg(ap, intmax_t);
	else if (options.content_size == 122) //does not work
		c = va_arg(ap, size_t);
    return(c);
}


void	put_sign()
{

}

int     content_int(t_opts options, va_list ap)
{
	char	*str;
	int		str_len;
	int 	n;
	int		neg;

	n = content_sizing(options, ap);
	neg = (n < 0) ? 1 : 0;
	str = pf_itoa(va_arg(options, int); //abs?
	if ()
		// str =padd_string_left(string, &length, special, str);
	if ()
		// str = padd_string_right(string, length, special, str);
	if ()
		
    pf_putstr(str);
	str_len = ft_strlen(str);
	// free(str);
	return(str_len);

}