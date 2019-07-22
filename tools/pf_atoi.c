/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 17:30:43 by ssettle           #+#    #+#             */
/*   Updated: 2019/07/22 14:34:35 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	pf_atoi(const char *str)
{
	int i;
	int sign;
	int nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while (str[i] == ' ' || str[i] == '\r' || str[i] == '\f' || str[i] == '\v'
			|| str[i] == '\t' || str[i] == '\n')
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
		{
			sign = -1;
		}
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + (str[i++] - '0');
	}
	return (nbr * sign);
}
