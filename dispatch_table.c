/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 12:12:04 by ssettle           #+#    #+#             */
/*   Updated: 2019/05/02 14:33:03 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_convert_table		g_convert_table[] = {
	{'c', &convert_char},
	{'d', &convert_int},
	{'f', &convert_float},
	{'i', &convert_int},
	{'o', &convert_octal},
	{'p', &convert_pointer},
	{'s', &convert_str},
	{'u', &convert_uint},
	{'x', &convert_hex},
	{'X', &convert_upper_hex}
};
