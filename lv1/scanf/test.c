#include <stdio.h>

int main(void)
{
	int c;
	FILE *fd = stdin;
	while ((c = fgetc(fd)) != '\n') // standard C I/O file reading loop
		putchar(c);

}
