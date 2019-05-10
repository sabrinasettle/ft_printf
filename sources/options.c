/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 10:38:53 by ssettle           #+#    #+#             */
/*   Updated: 2019/05/08 12:28:15 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** This function gets the flags and accesses the struct that contains them.
** It then sets the flag varibles to 0 and then valiadates the flags via the
** the functions in the vad_flag file. This is accessed through the (.) member
** access operator using the ~struct.anditsvarble~
*/

static t_flags		getz_theflagz(char **format)
{
	t_flags		flags;

	flags.plus = 0;
	flags.minus = 0;
	flags.space = 0;
	flags.zero = 0;
	flags.pound = 0;
	while (is_special_flag(**format))
	{
		add_flags(&flags, **format);
		(*format)++;
	}
	return (flags);
}

/*
** The field width: An optional decimal digit string (with nonzero first
** digit) specifying a minimum field width. If the converted value has
** fewer characters than the field width, it will be padded with spaces
** on the left (or right, if the left-adjustment flag has been given).
** Instead of a decimal digit string one may write "*" or "*m$"
** (for some decimal integer m) to specify that the field width
** is given in the next argument, or in the m-th argument, respectively,
** which must be of type int. A negative field width is taken as a '-' flag
** followed by a positive field width. In no case does a nonexistent or
** small field width cause truncation of a field; if the result of a
** conversion is wider than the field width, the field is expanded
** to contain the conversion result.
*/

static int			getz_width(char **format, va_list ap)
{
	int		width;

	width = 0;
	if (!IS_DIGIT(**format))
		return (false);
	if (IS_DIGIT(**format))
	{
		width = ft_atoi(*format);
		while (IS_DIGIT(**format))
			(*format)++;
	}
	else if (**format == '*')
	{
		width = va_arg(ap, int);
		(*format)++;
	}
	return (width);
}

/*
** If the precision is given as just '.', or the precision is negative,
** the precision is taken to be zero. This gives the minimum number of
** digits to appear for d, i, o, u, x, and X conversions, the number of
** digits to appear after the radix character for a, A, e, E, f, and F
** conversions, the maximum number of significant digits for g and G
** conversions, or the maximum number of characters to be printed from a
** string for s and S conversions.
**
** ex: ft_printf("%8.2f", 10.3456) = '   10.35'
*/

static int			getz_theprecision(char **format, va_list ap)
{
	int		mod_prec;

	mod_prec = -1;
	if (**format != '.')
		return (false);
	if (**format == '.')
	{
		mod_prec = 0;
		(*format)++;
		if (IS_DIGIT(**format))
		{
			while (IS_DIGIT(**format))
				(*format)++;
		}
		else if (**format == '*')
		{
			mod_prec = va_arg(ap, int);
			(*format)++;
		}
	}
	return (mod_prec);
}

/*
** Length Modifiers specifies the size of the argument.
** converts into short, shortshort, long, long long, int_max, size_t depending
** on the input, respectively : h, hh, l, ll, j, z
*/

static int			getz_thelength(char **format)
{
	int		len;

	len = 0;
	while (IS_LEN_OPT(**format))
	{
		if (**format == 'h' && *(*format + 1) != 'h')
			len = 104;
		else if (**format == 'h' && *(*format + 1) == 'h')
			len = 208;
		else if (**format == 'l' && *(*format + 1) != 'l')
			len = 108;
		else if (**format == 'l' && *(*format + 1) == 'l')
			len = 216;
		else if (**format == 'j')
			len = 106;
		else if (**format == 'z')
			len = 122;
		if (len > 0)
			(*format) += (len >= 130 ? 2 : 1);
	}
	return (len);
}

t_opts				getz_theoptionz(char **format, va_list ap)
{
	t_opts	options;

	options.flags = getz_theflagz(format);
	options.length = getz_thelength(format);
	options.precision = getz_theprecision(format, ap);
	options.width = getz_width(format, ap);
	return (options);
}
