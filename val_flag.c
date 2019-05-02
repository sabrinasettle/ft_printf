/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 10:42:43 by ssettle           #+#    #+#             */
/*   Updated: 2019/05/01 16:20:49 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		is_flag(char c)
{
	return (c == '#' || c == '-' || c == '+' || c == ' ' || c == '0');
}

void	add_flag(t_flags *flags, char c)
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
