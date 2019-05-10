/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:59:31 by ssettle           #+#    #+#             */
/*   Updated: 2019/05/09 11:05:42 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/*
** A % followed by another % character will write a single % to the stream.
*/

int	conv_percent(t_opts f_opts, va_list ap)
{
	(void)f_opts;
	(void)ap;
	ft_putchar('%');
	return (0);
}
