#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s) + i == (unsigned char *)c)
			return (((unsigned char *)s) + i);
		i++;
	}
	return (NULL);
}

void	*ft_memrchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = n - 1;
	while (i >= 0)
	{
		if (((unsigned char *)s) + i == (unsigned char *)c)
			return (((unsigned char *)s) + i);
		i--;
	}
	return (NULL);
}