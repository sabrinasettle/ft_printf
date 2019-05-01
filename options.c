/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 10:38:53 by ssettle           #+#    #+#             */
/*   Updated: 2019/05/01 14:59:48 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** This function gets the flags
*/

static t_flags	get_theflagz(char **str)
{
	t_flags		flags;

	flags.plus = 0;
	flags.minus = 0;
	flags.space = 0;
	flags.zero = 0;
	flags.pound = 0;

	while (is_flag(**str))
	{
		add_flag(&flags, **str);
		(*str)++;
	}
	return (flags);
}

static int		getz_width(char **str, va_list ap)
{
	int 	width;

	width = 0;
	if(IS_DIGIT(**str))
	{
		flags-> atoi(str)
	}
}

static int		getz_theprecision()
