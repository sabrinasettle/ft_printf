
# Ft_Printf

Convert the things into other things.

A reprogramming of the Standard Input Output library function printf().

# Installation if you are into that kinda thing

git clone this code

and use the make command in the terminal :)

then test to your hearts content with the main.c provided in the mains folder

# Print_f function
![700px-Printf svg](https://user-images.githubusercontent.com/22520221/57039545-c8c35880-6c11-11e9-9fb3-3053424749e5.png)
image from Wikipedia

Print_f is a function from the stdio.h C library
from the man: "In between there may be (in this order) zero or more flags, an optional minimum field width, an optional precision and an optional length modifier."

When using printf the function you must insert the appropiate conversion charcters in the *controlString*. These conversions are anounced by a percentage sign:
> %c

%c is the conversion specifier for a char charcter. But there many others to convert. the Ft_printf printf recreation was built to handle these conversions, any others are bonuses for the project:
- %i : integar (base 10)
- %d : decimal (integar) number (base 10)
- %s : string of characters
- %p : pointer address
- %f : floating-point number
- %o : octal bumber (base 8)
- %u : unsigned decimal (integar) number
- %x %X : number in hexadecimal (base 16)
- %% : print a precent sign

Along with conversions printf handles flags which can deteremine where or whether you will have padding.
Printf flags:
- '-' : creates a left justifying printf output
- '0' : integar zero-fill, left-pads the number with zeros instead of spaces
- '+' : means when used it will print a plus sign before the output
- '#' : Used with the specifiers the value is precceeded with 0, 0x or 0X for values different than 0
- ' ': If no sign is going to be written, a blank space is inserted before the value.

Width is determined for integars by placing a number after the persent sign and before the specifier flag. like so:
> printf("%5d", 10)

for strings it is similar:
> printf("%10s","Hello")

%[flag][min width][precision][length modifier][conversion specifier]

Length flags are demonstrated very well in this chart from http://www.cplusplus.com/reference/cstdio/printf/
<img width="672" alt="Screen Shot 2019-07-22 at 8 29 39 PM" src="https://user-images.githubusercontent.com/22520221/61680806-c841d780-acbf-11e9-9921-0c24b2e6db6e.png">




**Recreation**
The printf is incredibly useful, especially in considration to the fact that in the 42 pedagogy one can not use the function until it has been recreated. The function itself is called as such:

> printf (const char *format, ...);

it uses a va_list to access a stack of previously undefined parameters. The va_ family of macros uses a stack pointer, which points to the beginning of a varible list thence 'va_list'. This list is accessed from the arg passed to the 'va_start', the beginning of the stack, and then the 'va_args' nabs values from the stack as it goes through stack or list of potential arguements.

Some absolutely great references:
- https://alvinalexander.com/programming/printf-format-cheat-sheet
- http://www.cplusplus.com/reference/cstdio/printf/
- https://linux.die.net/man/3/printf
- https://www.cprogramming.com/tutorial/c/lesson17.html
- https://oded.blog/2017/05/24/printf/
- https://www.menie.org/georges/embedded/small_printf_source_code.html
- https://alvinalexander.com/programming/printf-format-cheat-sheet
- http://www.ryanjuckett.com/programming/printing-floating-point-numbers/

Great article on dispatch tables:
- https://blog.alicegoldfuss.com/function-dispatch-tables/
