/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:59:31 by ssettle           #+#    #+#             */
/*   Updated: 2019/05/10 09:16:35 by ssettle          ###   ########.fr       */
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
	pf_putchar('%');
	return (0);
}