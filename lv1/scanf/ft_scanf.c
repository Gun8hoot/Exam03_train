// NOT FINISHED !!

#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

int	ft_atoi(char *str)
{
	int nb = 0;
	int sign = 1;
	int i = 0;

	if (!str)
		return (0);
	if (nb[0] == '-')
		sign = -sign;
	while (str[i])
	{
		if (!(str[i] > '0' && str[i] < '9'))
			return (0);
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (sign * nb);
}

int match_space(FILE *f)
{
        // You may insert code here
    return (0);
}

int match_char(FILE *f, char c)
{

        // You may insert code here
    return (0);
}

int scan_char(FILE *f, va_list ap)
{
        // You may insert code here
    return (0);
}

int scan_int(FILE *f, va_list ap)
{
    
    return (0);
}

int scan_string(FILE *f, va_list ap)
{
	char *str = va_arg(ap, %s);
	char  c;
	int	  i = 0;

	while ((c = fgetc(f)) != EOF)
	{
		ap[i] = c;
		i++;
	}
    return (0);
}


int	match_conv(FILE *f, const char **format, va_list ap)
{
	switch (**format)
	{
		case 'c':
			return scan_char(f, ap);
		case 'd':
			match_space(f);
			return scan_int(f, ap);
		case 's':
			match_space(f);
			return scan_string(f, ap);
		case EOF:
			return -1;
		default:
			return -1;
	}
}

int ft_vfscanf(FILE *f, const char *format, va_list ap)
{
	int nconv = 0;
	char *str;

	if (c == EOF)
		return EOF;
	ungetc(c, f);

	while (*format)
	{
		if (*format == '%' && *format + 1 != '\0')
		{
			format++;
			if (match_conv(f, &format, ap) != 1)
				break;
			else
				nconv++;
		}
		else if (isspace(*format))
		{
			if (match_space(f) == -1)
				break;
		}
		else if (match_char(f, *format) != 1)
			break;
		format++;
	}
	
	if (ferror(f))
		return EOF;
	return nconv;
}


int ft_scanf(const char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	int ret = ft_vfscanf(stdin, format, ap);
	va_end(ap);
	return ret;
}

int main(void)
{
	char str[999];
	char sss[999];
	scanf("%s | %s", &str, &sss);
	printf("%s | %s\n", str, sss);
}
