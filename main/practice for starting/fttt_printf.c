#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

// ************************************ TOOLS *********************************

size_t	ft_strlen(const char *str)
{
	int c;

	c = 0;
	while (str[c] != '\0')
		c++;
	return (c);
}


char	*ft_strcpy(char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char		*ft_strdup(const char *src)
{
	char	*s2;

	s2 = (char*)malloc(sizeof(*s2) * (ft_strlen(src) + 1));
	if (!s2)
	{
		return (NULL);
	}
	s2 = ft_strcpy(s2, src);
	return (s2);
}


// ****************************************************************************


int ftt_vprintf(int fd, const char *format, va_list arg) // va_list arg
{
	int i;
	char *string;
	char *str;
	int len;

	i = 0;
	string = ft_strdup(format);
	while(string[i] != '\0')
	{
		if (string[i] == '%')
		{
			if(string[i + 1] == 's') //added
			{
				str = ft_strdup((char *)va_arg(arg, char *));
				len = ft_strlen(str);
				write(fd, str, len);
			}
			// write(fd, string, i);
		}
		i++;
	}
	write(fd, string, i);
	free(string);
	return(i);
}

int ftt_printf(const char *format, ...) // ...
{
	va_list arg;
	int done;

	va_start(arg, format);
	done = ftt_vprintf(1, format, arg);//stdout, ..., arg //amount of bytes read is the worker, does EVERYTHING according to sam
	va_end(arg); //ends the list of args
	return done; //returns the amount of bytes read
}


int main()
{
	// char *str = ft_strdup((char *)va_arg(arg, char *)); // this is for the dispatch tabke %s 
	ftt_printf("%s Print me mothafucka\n", "bet you wont\n"); 
	// ftt_printf("%Print me mothfucka");
	ftt_printf("Print me mothfucka"); //test to see if the percent sign works
	return(0);
}