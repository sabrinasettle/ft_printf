/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printingcolor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 14:16:02 by ssettle           #+#    #+#             */
/*   Updated: 2019/05/01 19:11:51 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Defines the color codes. BUT WHAT IS bred?? or any b for that matter?
*/

t_table g_colors[]
{
	{"{red}", "\033[31m"},
	{"{bred}", "\033[31;1m"},
	{"{green}", "\033[32m"},
	{"{bgreen}", "\033[32;1m"},
	{"{yellow}", "\033[33m"},
	{"{byellow}", "\033[33;1m"},
	{"{blue}", "\033[34m"},
	{"{bblue}", "\033[34;1m"},
	{"{purple}", "\033[35m"},
	{"{bpurple}", "\033[35;1m"},
	{"{cyan}", "\033[36m"},
	{"{bcyan}", "\033[36;1m"},
	{"{black}", "\033[30m"},
	{"{bblack}", "\033[30;1m"},
	{"{white}", "\033[37m"},
	{"{bwhite}", "\033[37;1m"},
	{"{b_red}", "\033[41m"},
	{"{b_bred}", "\033[41;1m"},
	{"{b_green}", "\033[42m"},
	{"{b_bgreen}", "\033[42;1m"},
	{"{b_yellow}", "\033[43m"},
	{"{b_byellow}", "\033[43;1m"},
	{"{b_blue}", "\033[44m"},
	{"{b_bblue}", "\033[44;1m"},
	{"{b_purple}", "\033[45m"},
	{"{b_bpurple}", "\033[45;1m"},
	{"{b_cyan}", "\033[46m"},
	{"{b_bcyan}", "\033[46;1m"},
	{"{b_black}", "\033[40m"},
	{"{b_bblack}", "\033[40;1m"},
	{"{b_white}", "\033[47m"},
	{"{b_bwhite}", "\033[47;1m"},
	{"{eoc}", "\033[0m"}
	{NULL, NULL},
};

t_bool	ft_coloring(t_opts *p_out, char **str)
{
	int index;

	index = 0;
	while (index < 34)
	{
		if (ft_strnstr(*str, g_colors[index][0], \
				ft_strlen(g_colors[index][0])) != 0)
			{
				ft_set_data(p_out, g_colors); //what where??
				*str = *str + ft_strlen(g_colors[index][0]);
				return (true);
			}
			index++;
	}
	return (false);
}

//https://github.com/vvysotsk/ft_printf/blob/master/src/bonus.c

//if (**format == '{' && (ft_color(f_out, format) == true))
		// return ;
