/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 19:18:36 by ssettle           #+#    #+#             */
/*   Updated: 2019/03/01 18:52:51 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	while (ft_isspace(s[i]))
		i++;
	while (ft_isspace(s[len - 1]))
		len--;
	len = len - i;
	if (!(str = (char*)ft_strnew(len >= 0 ? len : 0)))
		return (NULL);
	j = -1;
	while (++j < len)
		str[j] = s[i + j];
	str[j] = '\0';
	return (str);
}
