/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 19:37:27 by ssettle           #+#    #+#             */
/*   Updated: 2019/05/02 12:54:19 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	conv_perc(t_flags *flags)
{
	char *res;
	int len;

	res = ft_strdup("%");
	if (res)
		res =
}

int	convert(t_flags *flags, va_list *ap)
{
	char c;

	c = *flags->key;
	if (c == '%')
		return (conv_perc(flags)); //conv perc???
	else if (c == '')
}
