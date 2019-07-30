#include "../includes/ft_printf.h"

void pf_putstr(char *str)
{
	if (str)
		write(1, str, pf_strlen(str));
}
