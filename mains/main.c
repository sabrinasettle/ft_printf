
#include "../includes/ft_printf.h"
#include <stdio.h>

int	main()
{
	int		i;

	// Char tests
	// printf("%15s", "CHAR\n");
	printf("---------------------- CHAR ----------------------------- \n");
	pf_putchar('\n');
	printf ("prin: %c %c \n", 'a', 65);
	ft_printf("mine: %c %c \n", 'a', 65);
	pf_putchar('\n');
	printf ("prin: %c \n", 'a');
	ft_printf("mine: %c \n", 'a');
	pf_putchar('\n');
	printf ("l test prin: %lc \n", 'a'); 
	ft_printf("l test mine: %lc \n", 'a'); //returns c rather than 
	pf_putchar('\n');
	printf("prin: %5c\n", '$');
	ft_printf("mine: %5c\n", '$');
	pf_putchar('\n');
	printf("prin: %10c\n", '$');
	ft_printf("mine: %10c\n", '$');
	pf_putchar('\n');
	printf("prin minus: %-5c %c\n", '$', '%');
	ft_printf("mine minus: %-5c %c\n", '$', '%');
	pf_putchar('\n');
	//Check for null character
	i = printf("|%c|\n", '\0');
	printf("Return value: %d\n", i);
	i = ft_printf("|%c|\n", '\0');
	printf("Return value: %d\n", i);
	pf_putchar('\n');
	pf_putchar('\n');

	printf("---------------------- STRINGS ----------------------------- \n");
	pf_putchar('\n');
	printf ("pf a simple string: %s \n", "A string");
	ft_printf ("me a simple string: %s \n", "A string"); //printing a zero, null terminating char??
	pf_putchar('\n');
	printf ("pf prec test: %.5s \n", "abcdefg");
	ft_printf ("me prec test: %.5s \n", "abcdefg"); //printing a zero, null terminating char??
	pf_putchar('\n');
	printf ("pf prec and right pad: %-10.5s %c\n", "abcdefg", 's');
	ft_printf ("me prec and right pad: %-10.5s %c\n", "abcdefg", 's'); //printing a zero, null terminating char??
	pf_putchar('\n');
	printf ("pf 10 pad: %10s \n", "abcdefg");
	ft_printf ("me 10 pad: %10s \n", "abcdefg");
	pf_putchar('\n');
	printf ("pf string minus pad: %-10s%c\n", "A string",'c');
	ft_printf ("me string minus pad: %-10s%c\n", "A string",'c');
	pf_putchar('\n');
	printf("pf: hello, %s \n" , "gavin");
	ft_printf("me: hello, %s \n" , "gavin");
	//NULL Character check
	i = printf("|%s|\n", "\0");
	printf("Return value: %d\n", i);
	i = ft_printf("|%s|\n", "\0");
	printf("Return value: %d\n", i);
	pf_putchar('\n');
	pf_putchar('\n');
	// printf ("printf: %lls \n", "abcdefg");
	// ft_printf ("mine: %lls \n", "abcdefg");


	// Ints and Ds 
	printf("---------------------- I & D ----------------------------- \n");
	pf_putchar('\n');
	printf("pf: %d, %d\n", 42, 21);
	ft_printf("me: %d, %d\n", 42, 21);
	pf_putchar('\n');
	printf("pf: %d\n", -42);
	ft_printf("me: %d\n", -42);
	pf_putchar('\n');
	printf("pf: %d, %d, %d, %ld\n", 42, -21, 69,  -2174963257925); 
	ft_printf("me: %d, %d, %d, %ld\n", 42, -21, 69, -2174963257925); //delivers a different alue than printf
	pf_putchar('\n');
	printf("pf: %03d\n", 1993);
	ft_printf("pf: %.3d\n", 1993);
	pf_putchar('\n');
	printf("pf: %.3d\n", -1993);
	ft_printf("pf: %.3d\n", -1993);
	pf_putchar('\n');
	printf ("pf: %d %ld\n", 1977, 650000L);
	ft_printf ("me: %d %ld\n", 1977, 650000L);
	pf_putchar('\n');
	printf ("pf preceding with blanks: %10d \n", 1977);
	ft_printf("me preceding with blanks: %10d \n", 1977);
	pf_putchar('\n');
	printf ("pf: %10d \n", -1977);
	ft_printf("me: %10d \n", -1977);
	pf_putchar('\n');
	printf ("pf: %-10d \n", 1977);
	ft_printf("me: %-10d \n", 1977);
	pf_putchar('\n');
	printf ("pf: %-10d \n", -1977);
	ft_printf("me: %-10d \n", -1977);
	pf_putchar('\n');
	printf ("pf preceding with zeros: %010d \n", 1977);
	ft_printf("me preceding with zeros: %010d \n", 1977);
	pf_putchar('\n');
	printf("pf prec: %.6d\n", 1993);
	ft_printf("me prec: %.6d\n", 1993);
	pf_putchar('\n');
	pf_putchar('\n');


	//FLOATS
	// printf("")
	// ft_printf("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
	// printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);

	// ft_printf("Width trick: %*d \n", 5, 10);
	// printf ("Width trick: %*d \n", 5, 10);

	//OCT
	printf("---------------------- OCT ----------------------------- \n");
	pf_putchar('\n');
	printf("pf: %o \n", 1977);
	ft_printf("me: %o \n", 1977);
	pf_putchar('\n');
	printf("pf: %.2o \n", 1977);
	ft_printf("me: %.2o \n", 1977);
	pf_putchar('\n');
	printf("pf neg: %-5o %c\n", 1977, '.');
	ft_printf("me neg: %-5o %c\n", 1977, '.');
	pf_putchar('\n');
	printf("pf neg: %o \n", 2);
	ft_printf("me neg: %o \n", 2); //delivers wrong ouput
	pf_putchar('\n');
	printf("pf: %010o\n", 7);
	ft_printf("me: %010o\n", 7);
	pf_putchar('\n');
	printf("pf: 0x%08o\n", 7);
	ft_printf("me: 0x%08o\n", 7);
	pf_putchar('\n');
	printf("pf hash: %#8o\n", 7);
	ft_printf("me hash: %#8o\n", 7);
	pf_putchar('\n');
	printf ("pf: %#o \n", 100);
	ft_printf("me: %#o \n", 100);
	pf_putchar('\n');

	//HEX
	printf("---------------------- HEX ----------------------------- \n");
	pf_putchar('\n');
	printf("pf: %-x \n", 1600);
	ft_printf("me: %-x \n", 1600);
	pf_putchar('\n');
	printf("pf: %.7x \n", 1600);
	ft_printf("me: %.7x \n", 1600);
	pf_putchar('\n');
	printf("pf: %-5x %c \n", 1600, '.');
	ft_printf("me: %-5x %c \n", 1600, '.');
	pf_putchar('\n');
	printf("pf: %#x \n", 1600);
	ft_printf("me: %#x \n", 1600);
	pf_putchar('\n');
	printf("pf: %#-x \n", 1600);
	ft_printf("me: %#-x \n", 1600);
	pf_putchar('\n');
	printf("pf just zeros: %010x\n", 7);
	ft_printf("me just zeros: %010x\n", 7);
	pf_putchar('\n');
	printf("pf pre 0x str: 0x%08x\n", 7);
	ft_printf("me pre 0x str: 0x%08x\n", 7);
	pf_putchar('\n');
	printf("pf: %#010x\n", 7);
	ft_printf("me: %#010x\n", 7);
	pf_putchar('\n');
	printf("pf: %#08x\n", 7);
	ft_printf("me: %#08x\n", 7);
	pf_putchar('\n');
	pf_putchar('\n');

	//UINT
	// printf("---------------------- UINT ----------------------------- \n");
	// pf_putchar('\n');


	// printf("%15s\n", "STRINGS\n");



	// percent sign
	// printf("%15s", "PERCENT");
	printf("---------------------- PERCENT ----------------------------- \n");
	pf_putchar('\n');
	printf("pf percent: %%\n");
	ft_printf("me percent: %%\n");
	pf_putchar('\n');
	pf_putchar('\n');

	// int a = 42;
	// pf_putchar('\n');
	// pf_putchar('\n');
	// printf("%p\n", (void *) &a);




	
	// printf ("pf some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
	// ft_printf("me some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);



	// system("leaks test");
	return 0;
}

