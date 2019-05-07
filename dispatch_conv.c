/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 13:41:32 by ssettle           #+#    #+#             */
/*   Updated: 2019/05/07 15:56:26 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// https://github.com/jkimminau/ft_printf/blob/master/src/ft_printf_conv.c

int		dispatch_flags(char **str , va_list ap)
{

}

void	handle_ouput(t_opts f_opts, char **str, va_list ap)
{
	if (**str == '{' && (ft_coloring(f_opts, str) == true))
		return ;
	while (true)
	{
		if (getz_theflags(str))
			continue ;
		if (getz_thewidth(str, ap))
			continue ;
		if (getz_theprescion(str, ap))
			continue ;
		if (getz_thelength(str))
			continue ;
		if (**str == '\0')
			return ;

	}

}
