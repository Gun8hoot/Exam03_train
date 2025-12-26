#include "given_code_gnl.h"

char	*ft_strchr(char *s, int c)
{
	int	i = 0;
	if (!s || !c)
		return (NULL);
	while (s[i] != c && s[i])
		i++;
	if (s[i] == c)
		return (&s[i]);
	else
		return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t i = 0;
	if (!src && !dest)
		return (NULL);
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

size_t	ft_strlen(char *s)
{
	size_t	ret = 0;
	if (!s)
		return (0);
	while (s[ret])
		ret++;
	return (ret);
}

int	str_append_mem(char **s1, char *s2, size_t size2)
{
	size_t	size1 = ft_strlen(*s1);
	char	*tmp = malloc(sizeof(char) * (size2 + size1 + 1));
	if (!tmp)
		return (0);
	ft_memcpy(tmp, *s1, size1);
	ft_memcpy(&tmp[size1], s2, size2);
	tmp[size1 + size2] = 0;
	free(*s1);
	*s1 = tmp;
	return (1);
}

int	str_append_str(char **s1, char *s2)
{
	return (str_append_mem(s1, s2, ft_strlen(s2)));
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (!dest && !src)
		return (NULL);
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	else if (dest == src)
		return (dest);
	while (n > 0)
	{
		((char *)dest)[n - 1] = ((char *)src)[n - 1];
		n--;
	}
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	b[BUFFER_SIZE + 1] = "";
	char		*ret = NULL;
	int 		read_ret = 1;

	while (read_ret > 0 && !ft_strchr(ret, '\n'))
	{
		if (!str_append_str(&ret, b))
			return (NULL);
		read_ret = read(fd, b, BUFFER_SIZE);
		if (read_ret == -1)
			return (NULL);
		b[read_ret] = '\0';
	}
	if (!ret[0] && read_ret == 0)
		return (NULL);
	return (ret);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	int fd = open(argv[1], O_RDONLY);
	char *line;
	while ((line = get_next_line(fd)))
		printf("%s", line);
	return (0);
}
