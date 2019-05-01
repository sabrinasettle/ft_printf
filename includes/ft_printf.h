/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:01:16 by ssettle           #+#    #+#             */
/*   Updated: 2019/05/01 15:01:20 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <strdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "libft/libft.h"

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
	size_t					length;
	size_t					precision;
	size_t					fied_width;

}							t_opts;

typedef enum				e_bool
{
	false,
	true
}							t_bool;
/*
** FUNCTIONS
*/

void	add_flag(t_flags *flags, char c);


int		ft_printf(char *format, ...);
int		is_flag(char c);

#endif
