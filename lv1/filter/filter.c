#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define _GNU_SOURCE

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char *strjoin(char *s1, char *s2)
{
	char	*str;
	int		i = 0;
	int		j = 0;

	if (!s1 && !s2)
		return (NULL);
	str = malloc(sizeof(char) * (strlen(s1) + strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	if (s1)
		free(s1);
	return (str);
}

int main(int argc, char **argv)
{
	size_t sz = 1;
	char buff[BUFFER_SIZE + 1];
	char *str = NULL;
	if (argc != 2)
		return (1);
	while (sz > 0 && 1)
	{
		if (str)
			free(str);
		str = malloc(sizeof(char) * (1));
		if (!str)
			return 1;
		str[0] = '\0';
		while (memmem(str, strlen(str), "\n", 1) == NULL)
		{
			sz = read(0, &buff, BUFFER_SIZE);
			if (!buff[0])
				return (1);
			if (sz == 0)
				break;
			buff[sz] = '\0';
			str = strjoin(str, buff);
		}
		for (int i = 0; str[i]; i++)
		{
			if (str[i] == argv[1][0] && memmem(&str[i], strlen(argv[1]), argv[1], strlen(argv[1])))
			{
				for (size_t j = 0; j < strlen(argv[1]); j++)
				{
					str[i + j] = '*';
				}
			}
		}
		printf("%s", str);
	}
	if (str)
		free(str);
	return (0);
}
