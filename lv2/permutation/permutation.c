#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(char *str)
{
	size_t	len = 0;
	if (!str)
		return (len);
	while (str)
		len++;
	return (len);
}

void  swap(char *c1, char *c2)
{
	char save;

	save = *c2;
	*c2 = *c1;
	*c1 = save;
}

int permutation(int index, char *str, char *buff, size_t len)
{
	if (index == len)
	{
		buff[index] = '\0';
		puts(buff);
		return ;
	}
	for (int i = index; i < len; i++)
	{
		permutation(i + 1, str, buff, len);
		i++;
	}
	
	return (0);
}

void  show_res(char **arr)
{
	for (int i = 0; arr[i]; i++)
		puts(arr[i]);
}


int main(int argc, char **argv)
{
	char  **store = NULL;
	char  *str;

	if (argc != 2 || !argv[1][0])
		return (1);
	if ((store = malloc(sizeof(char *) * 1)) == NULL)
		return (1);
	if (permutation(0, argv[1], &store, ft_strlen(argv[1])) == 1)
	{
		free(store);
		return (1);
	}
	show_res(store);
	return (0);
}
