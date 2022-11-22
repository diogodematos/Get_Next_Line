#include "get_next_line.h"

char	*ft_strchr(const char *str, int b)
{
	int	a;

	a = 0;
	while (str[a])
	{
		if (str[a] == b)
			return ((char *)&str[a]);
		a++;
	}
	if (str[a] == b)
		return ((char *)&str[a]);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	int	a;

	a = 0;
	while (str[a])
		a++;
	return (a);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*dest;
	unsigned int	a;
	unsigned int	b;

	if (!s1 || !s2)
		return (0);
	dest = malloc ((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (!dest)
		return (0);
	a = 0;
	while (s1[a])
	{
		dest[a] = s1[a];
		a++;
	}
	b = 0;
	while (s2[b])
	{
		dest[a] = s2[b];
		a++;
		b++;
	}
	dest[a] = '\0';
	return (dest);
}

void	*ft_memset(void *str, int b, size_t n)
{
	unsigned char	*p;
	size_t			a;

	a = 0;
	p = (unsigned char *)str;
	while (a < n)
	{
		p[a] = (unsigned char)b;
		a++;
	}
	return (str);
}

void	*ft_calloc(size_t num, size_t size)
{
	unsigned int	array;
	char			*ptr;

	array = num * size;
	ptr = malloc (array);
	if (!ptr)
		return (0);
	ft_memset(ptr, 0, array);
	return (ptr);
}
