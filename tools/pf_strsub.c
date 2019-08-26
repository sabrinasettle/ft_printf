/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 17:12:04 by ssettle           #+#    #+#             */
/*   Updated: 2019/08/26 13:02:20 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pf_bzero(void *s, size_t n)
{
	pf_memset(s, 0, n);
}

void	*pf_memalloc(size_t size)
{
	void	*mem;

	mem = malloc(size);
	if (!mem)
		return (NULL);
	pf_bzero(mem, size);
	return (mem);
}

char	*pf_strnew(size_t size)
{
	return ((char*)pf_memalloc(size + 1));
}

char	*pf_strsub(char const *s, unsigned int start, size_t len)
{
	int				i;
	char			*str;

	i = 0;
	str = pf_strnew(len);
	if (!str || !s)
		return (NULL);
	while (len--)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
