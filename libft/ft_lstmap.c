/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:12:09 by ssettle           #+#    #+#             */
/*   Updated: 2019/02/28 18:26:31 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *nlist;

	nlist = 0;
	if (!lst)
		return (NULL);
	if (lst && f)
	{
		nlist = f(lst);
		if (nlist != NULL && lst->next != NULL)
			nlist->next = ft_lstmap(lst->next, f);
		return (nlist);
	}
	return (nlist);
}
