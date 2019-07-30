/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:01:16 by ssettle           #+#    #+#             */
/*   Updated: 2019/07/30 12:50:40 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h" //to be taken out later after pf_tool functions created

/*
** MACROS
*/
// # define IS_CON_TYPE(x)		(x == 's' || x == 'S')	//equal to any of the c conversion char types
// # define MAX_CONVERT_NUM 9
# define IS_DIGIT(c)		((c >= '0' && c <= '9') ? 1 : 0)
// # define IS_LEN_OPT(c)	if (c =

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
	uint32_t				width_field;
	int32_t					precision;
	uint32_t				width;
	int						total_length_opts;
}							t_opts;

// //all added becuase of sam
// typedef struct				s_env
// {
// 	int						total_length;
// 	char					*whatever_you_want; //jk just messing with sam, suppose to be a GREAT large str??
// 	t_opts					options;
// }							t_env;

typedef enum				e_bool //do I use this??
{
	false = 0,
	true = 1
}							t_bool;

typedef int					(*t_conv)(t_opts, va_list); //eli says could be void as well

typedef struct				s_dispatch_table
{
	char					form_convert;
	const t_conv			convert; //here lies the issue I think...
}							t_dispatch_table;

/*
**	Global Varibles
*/

extern const				t_dispatch_table g_convert_table[];

/*
*******************************   FUNCTIONS   *******************************
*/

void						add_flags(t_flags *flags, char c);
int							convert_args(const char **format, va_list ap);
int							ft_printf(const char *format, ...);
int							is_special_flag(char c);
int 						v_parse(const char *format, va_list ap);

/*
** CONVERSION SPECIFER FUNCTIONS
*/

int							convert_char(t_opts options, va_list ap);
int							convert_float(t_opts options, va_list ap);
int							convert_hex(t_opts options, va_list ap);
int							convert_int(t_opts options, va_list ap);
int							convert_octal(t_opts options, va_list ap);
int							convert_percent(t_opts options, va_list ap);
int							convert_pointer(t_opts options, va_list ap);
int							convert_str(t_opts options, va_list ap);
int							convert_uint(t_opts options, va_list ap);
int							convert_upper_hex(t_opts options, va_list ap);
int							convert_upper_uint(t_opts options, va_list ap);


/*
** PADDING
*/

char						*padding_octal(char *s, int len, t_opts options);
char						*padding_p(char *s, t_opts options);
char						*padding_l_an_u_h(char *s, int len, t_opts options);


/*
** TOOLS
*/

char						*pf_strcpy(char *s1, const char *s2);
char						*pf_strdup(const char *src);
int							pf_atoi(const char *str);
int							int_putchar(char c);
size_t						pf_strlen(const char *str);
void						pf_putchar(char c);
void 						pf_putstr(char *str);

/*
** OPTION FUNCTION
*/

t_opts						getz_theoptionz(const char **format, va_list ap);

/*
** BONUSES
*/

// t_bool						ft_coloring(t_opts *p_out, const char *str);

#endif
