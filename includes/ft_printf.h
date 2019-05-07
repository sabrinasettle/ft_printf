/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:01:16 by ssettle           #+#    #+#             */
/*   Updated: 2019/05/07 15:55:08 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <strdarg.h>
# include <unistd.h> //never used write right?
# include <stdlib.h>
# include "libft/libft.h"

/*
** MACROS
*/

# define IS_DIGIT(c)		((c >= '0' && c <= '9') ? 1 : 0)
// # define IS_LEN_OPT(c)		(c == 'h' || c == 'l' || c == 'j' || c == 'z')

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
	//char 					*key;
	// char					*flagsstr; //maybe??
}							t_flags;

typedef struct				s_opts
{
	t_flags					flags;
	size_t					length;
	size_t					precision;
	size_t					width;
}							t_opts;

typedef enum				e_bool
{
	false = 0,
	true = 1
}							t_bool;

//convert options could be an int or it could be a void
(*pointer)(arguments it takes, t_opts, va_list);

typedef struct s_dispatch_opts
{
	char output;


}				t_dispatch_opts;

t_spec //dispatch type
pointer to function

// typedef struct	s_data
// {
// 	char flags;
// 	char length;
// 	char spec;
// 	int width;
// 	int precision;
// }				t_data;



// typedef struct	s_f_out
// {
// 	size_t		len;
// 	size_t		space;
// 	char		*data;
// }				t_f_out;




/*
**	Global
*/

t_convert_table		g_convert_table[];

/*
** FUNCTIONS
*/


void	add_flags(t_flags *flags, char c);

int		dispatch_flags(char **str , va_list ap);
int		ft_printf(char *format, ...);
int		is_flag(char c);

t_opts	getz_theoptions(char **str, va_list ap);

/*
** BONUSES
*/

t_bool	ft_coloring(t_opts *p_out, char **str);


#endif

// https://github.com/jkimminau/ft_printf
// typedef struct	s_flags
// {
// 	int			alt;
// 	int			zero;
// 	int			minus;
// 	int			plus;
// 	int			space;
// 	int			prec;
// 	int			width;
// 	int			strlen;
// 	char		*key;
// 	char		*flagstr;
// }				t_flags;

// t_flags			*free_flags(t_flags *flags);
// t_flags			*new_flags(void);
