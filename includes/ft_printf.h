#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <strdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "libft.h"


/*
** STRUCTS
*/

typedef struct				s_flags
{
	int						pound;
	int						minus;
	int						plus;
	int						space;
	int						zero;
}							t_flags;


/*
** FUNCTIONS
*/

int	ft_printf(char *format, ...);


#endif
