/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 11:42:04 by ssettle           #+#    #+#             */
/*   Updated: 2019/08/16 11:42:42 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	*pf_memset(void *b, int c, size_t ln)
{
	unsigned char *vc;

	vc = (unsigned char *)b;
	if (ln == 0)
		return (b);
	while (ln--)
	{
		*vc++ = (unsigned char)c;
	}
	return (b);
}