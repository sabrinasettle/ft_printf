/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 13:25:21 by ssettle           #+#    #+#             */
/*   Updated: 2019/05/01 16:03:32 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


static int	flagged(char **str, va_list ap)
{
	t_opts options;
	int i;
	int c;

	(*str)++; //what are you?????

}

static int	normal(char **str) //checks if normal so yeah
{

}

/*
** 
*/

int	ft_printf(char *str, ...)
{
	int		count;
	va_list	ap;  //

	count = 0;
	va_start(ap, str); //va_start????
	while (*format != '\0')
	{
		if (*str == '%')
		{
			count += flagged(&str, ap); //flagged??
			str++;
		}
		else
			count += normal(&str); //normal??
	}
	va_end(ap);
	return(count);
}
