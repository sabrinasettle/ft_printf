/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_append.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 15:47:32 by ssettle           #+#    #+#             */
/*   Updated: 2019/09/11 15:02:58 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*pf_append(char *subject, char *insert, int pos)
{
	char	*new_str;
	char	*buf;
	int		len;

	buf = pf_strnew(pf_strlen(subject));
	pf_strncpy(buf, subject, pos);
	len = pf_strlen(buf);
	pf_strcpy(buf + len, insert);
	len += pf_strlen(insert);
	pf_strcpy(buf + len, subject + pos);
	new_str = pf_strcpy(subject, buf);
	free(buf);
	return (new_str);
}
