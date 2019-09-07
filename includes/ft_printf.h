/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 03:49:08 by ssettle           #+#    #+#             */
/*   Updated: 2019/09/07 16:35:57 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h> //testing

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h" //to be taken out later after pf_tool functions created

/*
** MACROS
*/

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
	int						width_field;
	int32_t					precision;
	int				        content_size;
	int						total_length_opts;
}							t_opts;

typedef enum				e_bool //do I use this??
{
	false = 0,
	true = 1
}							t_bool;

typedef int					(*t_conv)(t_opts, va_list); //eli says could be void as well

typedef struct				s_dispatch_table
{
	char					form_convert;
	const t_conv			convert; 
}							t_dispatch_table;

/*
**	Global Varibles
*/

extern const				t_dispatch_table g_convert_table[];

/*
*******************************   FUNCTIONS   *******************************
*/


int		is_content_flag(char c);



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
** TOOLS
*/

char						*pf_strsub(char const *s, unsigned int start, size_t len);
char						*pf_strnew(size_t size);
char						*pf_strcpy(char *s1, const char *s2);
char						*pf_strncpy(char *s1, const char *s2, size_t n);
char						*pf_strdup(const char *src);
int							pf_atoi(const char *str);
int							int_putchar(char c);
size_t						pf_strlen(const char *str);
void						pf_putchar(char c);
void						*pf_memset(void *b, int c, size_t ln);
void 						pf_putstr(char *str);
// static int					get_nbr(uint64_t num);
char						*pf_itoa_i(int64_t value);
char						*pf_itoa_unsigned(uint64_t value); 
char			            *pf_itoa_base_l(long int value);
char			            *pf_itoa_base_ll(long long value);
char						*pf_itoa_o(uint64_t value);
char						*pf_itoa_hex(uint64_t value);
char						*pf_itoa_upper_hex(uint64_t value);
char						*pf_itoa_p(intptr_t value);
char						*pf_strcat(char *dest, const char *src);
char						*pf_strjoin(char const *s1, char const *s2);
char 						*pf_append(char *subject, char *insert, int pos);

/*
** OPTION FUNCTION
*/

t_opts						getz_theoptionz(const char **format, va_list ap);

/*
** BONUSES
*/

// t_bool						ft_coloring(t_opts *p_out, const char *str);

#endif