/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 10:39:33 by ssettle           #+#    #+#             */
/*   Updated: 2019/05/08 17:19:33 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** 1 width we print only the c, with 2 width we print
** a space AND the c.
*/


// static void	padding(char c, int size, int left_align)
// {
// 	if (!left_align && size)
// 		ft_putspaces(size - 1);
// 	ft_putchar(c);
// 	if (left_align && size)
// 		ft_putspaces(size - 1);
// }
void	padding(char , int , int left_align) //three parameters
{

}

int						convert_char(t_opts f_opts, va_list ap)
{
	unsigned char c;

	c = (unsigned char)va_arg(ap, int);
	padding(c, f_opts.width, f_opts.flags.minus);
	write(1, &c, 1);
	return (1);
}
