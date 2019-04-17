/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 19:18:25 by ssettle           #+#    #+#             */
/*   Updated: 2019/03/04 17:28:19 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**strs;
	int		numwords;
	int		len;
	int		i;

	if (!s || !c)
		return (NULL);
	i = 0;
	numwords = ft_wordcount((char*)s, c);
	if (!(strs = (char**)malloc((sizeof(char*) * (numwords + 1)))))
		return (NULL);
	while (numwords--)
	{
		while (*s == c && *s)
			s++;
		len = ft_wordlen(s, c);
		if (!(strs[i] = ft_strsub(s, 0, len)))
			return (NULL);
		s += len;
		i++;
	}
	strs[i] = NULL;
	return (strs);
}
