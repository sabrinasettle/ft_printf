/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:10:13 by ssettle           #+#    #+#             */
/*   Updated: 2019/09/11 15:10:45 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pf_putstr(char *str)
{
	if (str)
		write(1, str, pf_strlen(str));
}

int		pf_putstr_i(char *str)
{
	int i;

	i = 0;
	if (str)
		write(1, str, (i = pf_strlen(str)));
	return (i);
}
