/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_octal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 19:50:01 by ssettle           #+#    #+#             */
/*   Updated: 2019/07/17 14:35:13 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*padding_octal(char *s, int len, t_opts options)
{
	char	*str;

	if (!(str = (char *)ft_strnew(options.width)))
		return ();
	ft_memset(str, ' ', options.width);
	if (options.flags.minus)
		ft_strncpy(str, s, len);
	else
		ft_strncpy(&str[options.width - len], s, len);
	free (s);
	return (str);
}
