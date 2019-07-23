// #include "../libft.h"
#include "../includes/ft_printf.h"
#include <stdio.h>

//https://github.com/agavrel/42-ft_printf/blob/master/misc/main.c

int	main()
{
	printf ("printf Characters: %c %c \n", 'a', 65);
	ft_printf("mine Characters: %c %c \n", 'a', 65);

	// ft_printf ("Decimals: %d %ld\n", 1977, 650000L);
	// printf ("Decimals: %d %ld\n", 1977, 650000L);

	// ft_printf("Preceding with blanks: %10d \n", 1977);
	// printf ("Preceding with blanks: %10d \n", 1977);

	// ft_printf("Preceding with zeros: %010d \n", 1977);
	// printf ("Preceding with zeros: %010d \n", 1977);

	// ft_printf("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
	// printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);

	// ft_printf("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
	// printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);

	// ft_printf("Width trick: %*d \n", 5, 10);
	// printf ("Width trick: %*d \n", 5, 10);

	// ft_printf ("%s \n", "A string");
	// printf ("%s \n", "A string");
	// ft_printf("Mine: hello, %s" , "gavin");
	// ft_printf("%%\n");
	// printf("%%\n");
	
	// system("leaks test"); FOR LATER
	return 0;
}

