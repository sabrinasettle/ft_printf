/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:59:31 by ssettle           #+#    #+#             */
/*   Updated: 2019/07/30 12:47:03 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** A % followed by another % character will write a single % to the stream.
*/

int	convert_percent(t_opts options, va_list ap)
{
	pf_putchar('%');
	(void)options;
	(void)ap;
	return (0);
}
