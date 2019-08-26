/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_octal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 12:33:46 by ssettle           #+#    #+#             */
/*   Updated: 2019/08/26 16:07:04 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// int     content_sizing(t_opts options, va_list ap)
// {
//     char c;
    
// 	if (options.content_size == 0)
// 		c = va_arg(ap, unsigned int);
// 	else if (options.content_size == 108) //does not work
// 		c = va_arg(ap, unsigned long int);
//     else if (options.content_size == 104) //does not work
// 		c = va_arg(ap, unsigned short int);
//     else if (options.content_size == 216) //does not work
// 		c = va_arg(ap, unsigned long long int);
// 	else if (options.content_size == 208) //does not work
// 		c = va_arg(ap, unsigned char); //same as signed char
// 	else if (options.content_size == 106) //does not work
// 		c = va_arg(ap, uintmax_t);
// 	else if (options.content_size == 122) //does not work
// 		c = va_arg(ap, size_t);
//     return(c);
// }

char *pf_append_oct(char *subject, char *insert, int pos) 
{
	char *new_str;
    char *buf;
	int len;
	
	buf = pf_strnew(pf_strlen(subject));
    pf_strncpy(buf, subject, (pos - 1)); 
    len = strlen(buf);
    pf_strcpy(buf + len, insert);
    len += pf_strlen(insert);
	pf_strcpy(buf + len, subject + pos);
    new_str = pf_strcpy(subject, buf);
	free(buf);
	return(new_str);
}


char		*padding_oct(t_opts options, char *str)
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

// minus numbers does somehting interesting, dont understand it at all for the most part
// pf neg: 37777774107
// me neg: 3671

int			convert_octal(t_opts options, va_list ap)
{
	char		*str;
	int			len;
	char		*new_str;
	
	// if (options.content_size > 0)
		// str = content_sizing(options, ap);
	str = pf_itoa_octal(va_arg(ap, int)); //abs?
	len = pf_strlen(str);
	if (options.width_field > len)
	{
		new_str = padding_oct(options, str);
		if (options.flags.pound >= 1)
			new_str = pf_append_oct(new_str, "0" , pf_strlen(new_str) - 1);
		pf_putstr(new_str);
		free(new_str);
	}
	else 
		pf_putstr(str);
	len = pf_strlen(str);
	free(str);
	return(len);
}


// if (!(str = ft_itoa_base(num, 8, 'a')))
// 		exit(-1);

// str = pf_itoa(n, param, sign);

// char			*ft_itoa_base(int value, int base)
// others take three parameters looks like , intmax_t, a number or struct, and a char





// char	*octal_create(iptr_t int_ptr) //correct parameters???
// {
// 	// int		i;
// 	char	*res;
// 	char	*octal;

// 	if(!(res = (char *)malloc(sizeof(char*))))
// 		return(-1);
// 	octal = "01234567";
// 	if (!int_ptr)
// 		res[i] = '0';
// 	while (int_ptr)
// 	{
// 		res[i] = octal[int_ptr % 8];
// 		int_ptr /= 8;
// 		i++;
// 	}
// 	res = ft_strlen(res);
// 	return (res);
// }