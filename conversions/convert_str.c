/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 12:33:59 by ssettle           #+#    #+#             */
/*   Updated: 2019/06/06 15:23:21 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// https://github.com/spitox/ft_printf/blob/master/srcs/print_s.c
// https://github.com/NicoGGG/ft_printf.2/blob/master/src/pf_putstr.c
// https://github.com/MagicHatJo/-42-ft_printf/blob/master/type/d_s.c
// https://github.com/cbg119/42-ft_printf/blob/master/conversions/convert_s.c

static int parse(t_opts f_opts, int j, char *str)
{
	int 	i;
	t_flags flags;

	i = 0;
	while (f_opts.field_length && f_opts.field_length - i > j && !(flags.minus))
	{
		pf_putchar(flags.zero ? '0' : ' ');
		i++;
	}
	j = 0;
	if ((int)pf_strlen(str) > f_opts.field_length && f_opts.precision != -1)
	{
		while (j < f_opts.precision && str[j])
		{
			pf_putchar(str[j]);
			i++;
			j++;
		}
	}
	else
		i += (int)write(1, str, pf_strlen((char *)str));
	return (i);

}

//will need to put null terminator at the end of the string as usual
int			convert_str(t_opts f_opts, va_list ap)
{
	char	*s;
	int		i;
	int		j;
	t_flags	flags;

	i = 0;
	s = va_arg(ap, char *);
	{
		free(s);
		s = "(null)";
	}
	if (f_opts.precision == -1)
		f_opts.precision = 0;
	else if (f_opts.precision == 0)
		f_opts.precision = -1;
	j = ((int)pf_strlen(s) > f_opts.precision && f_opts.precision != -1) ?
		f_opts.precision : (int)pf_strlen(s);
	i += parse(f_opts, j, s);
	while (f_opts.field_length && f_opts.width > j && flags.minus)
	{
		pf_putchar(' ');
		f_opts.field_length--;
		i++;
	}
	return (i);
}
