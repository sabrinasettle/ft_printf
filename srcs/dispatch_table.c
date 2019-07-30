/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 12:12:04 by ssettle           #+#    #+#             */
/*   Updated: 2019/07/29 15:40:06 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** A function or dispatch table also known a a jump table is an array of
** function pointers. In this case its use is to access the convert functions
** from their separate files. It is connected to the s_convert_table struct in
** the .h file.
*/

const	t_dispatch_table		g_convert_table[] = {
	{'c', &convert_char},
	{'C', &convert_char},
	// {'s', &convert_str},
	// {'S', &convert_str},
	// {'f', &convert_float},		//with the flags l and L
	// {'p', &convert_pointer},
	// {'d', &convert_int},			//with the flags hh, h, l, and ll
	// {'i', &convert_int},			//with the flags hh, h, l, and ll
	// {'o', &convert_octal},		//with the flags hh, h, l, and ll
	// {'u', &convert_uint},		//with the flags hh, h, l, and ll
	// {'x', &convert_hex},			//with the flags hh, h, l, and ll
	// {'X', &convert_upper_hex}, 	//with the flags hh, h, l, and ll
	{'%', &convert_percent} //proably not working
};
