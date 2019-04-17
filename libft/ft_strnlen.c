/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 19:59:48 by ssettle           #+#    #+#             */
/*   Updated: 2019/03/01 13:13:28 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnlen(const char *str, size_t maxlen)
{
	size_t len;

	len = 0;
	while (str[len] != '\0' && len < maxlen)
		len++;
	return (len);
}
