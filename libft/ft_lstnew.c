/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 11:53:56 by ssettle           #+#    #+#             */
/*   Updated: 2019/02/28 18:28:51 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *nlist;

	if (!(nlist = (t_list *)malloc(sizeof(*nlist))))
		return (NULL);
	if (!content)
	{
		nlist->content = NULL;
		nlist->content_size = 0;
	}
	else
	{
		if (!(nlist->content = malloc(content_size)))
		{
			free(nlist);
			return (NULL);
		}
		ft_memcpy((nlist->content), content, content_size);
		nlist->content_size = content_size;
	}
	nlist->next = NULL;
	return (nlist);
}
