/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 09:34:34 by ssettle           #+#    #+#             */
/*   Updated: 2019/07/18 16:12:47 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int v_parse(const char *format, va_list ap)
{
    size_t i;
    size_t len;
    char *string;
    t_opts options;
    // char *str; do I need??

    i = 0;
    len = 0;
    string = ft_strdup(format);
    while (string[i] != '\0')
    {
        if(string[i] == '%') //is equal to any of the flags for conversion type
        {
            len += convert_args(format, ap);
        }
        
    }
    return(len);
}







// from working with Sam


// int ftt_vprintf(int fd, const char *format, va_list arg) // va_list arg
// {
// 	int i;
// 	char *string;
// 	char *str;
// 	int len;

// 	i = 0;
// 	string = ft_strdup(format);
// 	while(string[i] != '\0')
// 	{
// 		if (string[i] == '%')
// 		{
// 			if(string[i + 1] == 's') //added
// 			{
// 				str = ft_strdup((char *)va_arg(arg, char *));
// 				len = ft_strlen(str);
// 				write(fd, str, len);
// 			}
// 			// write(fd, string, i);
// 		}
// 		i++;
// 	}
// 	write(fd, string, i);
// 	free(string);
// 	return(i);
// }