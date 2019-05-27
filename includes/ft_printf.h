/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:01:16 by ssettle           #+#    #+#             */
/*   Updated: 2019/05/15 11:55:55 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h> //never used write right?
# include <stdlib.h>
# include "../libft/libft.h"

/*
** MACROS
*/

# define MAX_CONVERT_NUM 9
# define IS_DIGIT(c)		((c >= '0' && c <= '9') ? 1 : 0)

/*
** STRUCTS
*/

typedef struct				s_flags
{
	int						plus;
	int						minus;
	int						space;
	int						zero;
	int						pound;
}							t_flags;

typedef struct				s_opts
{
	t_flags					flags;
	size_t					field_length;
	size_t					precision;
	size_t					width;
}							t_opts;

typedef enum				e_bool
{
	false = 0,
	true = 1
}							t_bool;

typedef int					(*f_conv)(t_opts, va_list);

typedef struct	s_convert_table
{
	char 			form_convert;
	const f_conv	convert;

}				t_convert_table;

/*
**	Global Varibles
*/

extern const				t_convert_table g_convert_table[];

/*
*******************************   FUNCTIONS   *******************************
*/

void				add_flags(t_flags *flags, char c);

int					convert_args(char **format , va_list ap);
int					ft_printf(char *format, ...);
int					is_special_flag(char c);

/*
** CONVERSION SPECIFER FUNCTIONS
*/

int					convert_char(t_opts f_opts, va_list ap);
int					convert_float(t_opts f_opts, va_list ap);
int					convert_hex(t_opts f_opts, va_list ap);
int					convert_int(t_opts f_opts, va_list ap);
int					convert_octal(t_opts f_opts, va_list ap);
int					convert_pointer(t_opts f_opts, va_list ap);
int					convert_str(t_opts f_opts, va_list ap);
int					convert_uint(t_opts f_opts, va_list ap);
int					convert_upper_hex(t_opts f_opts, va_list ap);
int					convert_upper_uint(t_opts f_opts, va_list ap);

/*
** PADDING
*/



/*
** TOOLS
*/

void				pf_putchar(char c);
int					pf_atoi(const char *str);
size_t				pf_strlen(const char *str);


/*
** OPTION FUNCTION
*/

t_opts				getz_theoptionz(char **format, va_list ap);

/*
** BONUSES
*/

// t_bool				ft_coloring(t_opts *p_out, char **format);


#endif
