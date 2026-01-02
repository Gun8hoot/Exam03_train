#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

int match_space(FILE *f)
{
	char c;
	while ((c = fgetc(f)) != EOF && isspace(c))
		;
	if (c != EOF)
		ungetc(c, f);
    return (1);
}

int match_char(FILE *f, char c)
{
	char fgc = fgetc(f);
	ungetc(fgc, f);
	if (c == fgc)
		return (1);
    return (1);
}

int scan_char(FILE *f, va_list ap)
{
	char *ptrc = va_arg(ap, char *);
	int c = fgetc(f);
	ungetc(c, f);
	if (!isspace(c))
		*ptrc = c;
	else
		return (0);
	return (1);
}

int scan_int(FILE *f, va_list ap)
{
	int	  *ptri = va_arg(ap, int *);
	int	  converted = 0;
	int  c;

	c = fgetc(f);
	if (!isdigit(c))
	{
		ungetc(c, f);
		return (0);
	}
	while (isdigit(c) && c != EOF)
	{
		converted = converted * 10 + (c - '0');
		c = fgetc(f);
	}
	*ptri = converted;
	ungetc(c, f);
    return (1);
}

int scan_string(FILE *f, va_list ap)
{
	char  *ptr = va_arg(ap, char *);
	int	  c = fgetc(f);
	int	  i = 0;

	if (c == EOF || isspace(c))
	{
		ungetc(c, f);
		return (0);
	}
	while (c != EOF && !isspace(c))
	{
		ptr[i] = c;
		i++;
		c = fgetc(f);
	}
	ptr[i] = '\0';
	ungetc(c, f);
    return (1);
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
	char  str[999];
	char  sss[999];
	int	  dig;
	int	  dig2;
	int	  dig3;
	scanf("%d %s %d", &dig, &sss, &dig3);
	printf("%d %s %d\n", dig, sss, dig3);
}
