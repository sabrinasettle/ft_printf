/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 12:33:39 by ssettle           #+#    #+#             */
/*   Updated: 2019/05/12 19:51:52 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// https://github.com/spitox/ft_printf/blob/master/srcs/print_x.c
// https://github.com/cbg119/42-ft_printf/blob/master/conversions/convert_x.c
// https://github.com/spitox/ft_printf/blob/master/padding/print_x_option.c
// https://github.com/MagicHatJo/-42-ft_printf/blob/master/type/d_x.c


static void error_check(t_opts f_opts)
{
	(void)f_opts;
}

int		convert_hex(t_opts f_opts, va_list ap)
{
	int i;
	// char


	error_check(f_opts);
}
