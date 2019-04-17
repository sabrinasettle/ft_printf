/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 19:18:09 by ssettle           #+#    #+#             */
/*   Updated: 2019/02/28 19:15:19 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	i;

	if (!s || !f)
		return (NULL);
	i = -1;
	if (s && f)
	{
		if (!(str = ft_strnew(ft_strlen(s))))
			return (NULL);
		while (s[++i])
			str[i] = f(s[i]);
		return (str);
	}
	return (NULL);
}
