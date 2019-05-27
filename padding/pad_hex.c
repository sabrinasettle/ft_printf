/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 19:49:55 by ssettle           #+#    #+#             */
/*   Updated: 2019/05/13 15:44:14 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
//https://github.com/spitox/ft_printf/blob/master/srcs/print_x.c

static int	split(int n, int tmp, int len, t_opts f_opts)
{
	t_flags flags;

	while (tmp > 0 && !flags.minus)
	{
		if(flags.zero && !f_opts.precision)
			pf_putchar('0');
		else
			pf_putchar(' ');
		tmp--;
		len++;
	}
	if( == -1)
	{
		len += 2;
		write(1, "0x", 2);
	}
}

static int	split_twice(int n, int *tmp, int len, t_opts f_opts)
{
	if(n)
		tmp -= 2;
	if()
	{
		write(1, "0x", 2);
		len += 2;
	}
	return (len);
}

static int	split_three(int n, int i, t_opts f_opts)
{
	

}
