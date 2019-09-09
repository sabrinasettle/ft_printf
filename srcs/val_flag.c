/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 10:42:43 by ssettle           #+#    #+#             */
/*   Updated: 2019/09/08 19:36:12 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** '-' : Left-justify within the given field width
** '+' : Forces to preceed the result with a plus or minus sign
** ' ' : A blank space is inserted before the result
** '#' : Used with o, x or X specifiers the value is preceeded with 0, 0x or
**       0X respectively for values different than zero. Used with a, A, e, E,
**		 f, F, g or G it forces the written output to contain a decimal point
**		 even if no more digits follow.
** '0' : Left-pads the number with zeroes (0) instead of spaces when padding.
*/


// int		prt_is_length(char c)
// {
// 	return (c == 'h' || c == 'l' || c == 'j' || c == 'z') ? (1) : (0);
// }


int		is_special_flag(char c)
{
	if (c == '#' || c == '-' || c == '+' || c == ' ' || c == '0')
		return(1);
	return(0);
}

void	add_flags(t_flags *flags, char c)
{
	if (c == '#')
		flags->pound = 1;
	else if (c == '-')
		flags->minus = 1;
	else if (c == '+')
		flags->plus = 1;
	else if (c == ' ')
		flags->space = 1;
	else if (c == '0')
		flags->zero = 1;
}
