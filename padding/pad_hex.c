/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 19:49:55 by ssettle           #+#    #+#             */
/*   Updated: 2019/06/02 11:24:04 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*padding_p(char *s, t_opts opts)
{
	char	*str;

	if (!(str = (char *)pf_strnew(opts.width)))
		return ();
	pf_memset(str, ' ', opts.width);
	if (opts.flags.minus)
		pf_strncpy(str, s, 14);
	else
		pf_strncpy(&str[opts.width - 14], s, 14);
	free(s);
	return (str);
}

char	*padding_lh(char *s, int len, t_opts opts)
{
	char	*str;

	if (!(str = (char *)))

}
