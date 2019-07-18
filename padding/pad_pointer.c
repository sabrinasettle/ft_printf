/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_pointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 19:50:03 by ssettle           #+#    #+#             */
/*   Updated: 2019/07/17 14:35:13 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*padding_p(char *s, t_opts options)
{
	char	*str;

	if (!(str = (char *)ft_strnew(options.width)))
		return ();
	ft_memset(str, ' ', options.width);
	if (options.flags.minus)
		ft_strncpy(str, s, 14);
	else
		ft_strncpy(&str[options.width - 14], s, 14);
	free(s);
	return (str);
}
