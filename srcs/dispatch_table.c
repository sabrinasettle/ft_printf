/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 12:12:04 by ssettle           #+#    #+#             */
/*   Updated: 2019/07/11 20:11:06 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** A function or dispatch table also known a a jump table is an array of
** function pointers. In this case its use is to access the convert functions
** from their separate files. It is connected to the s_convert_table struct in
** the .h file.
*/

const	t_convert_table		g_convert_table[] = {
	{'c', &convert_char},
	{'s', &convert_str},
	// {'p', &convert_pointer},
	// {'d', &convert_int},
	// {'f', &convert_float},
	// {'i', &convert_int},
	// {'o', &convert_octal},
	// {'u', &convert_uint},
	// {'x', &convert_hex},
	// {'X', &convert_upper_hex},
	// {'%', &convert_percent} //proably not working
};
