#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	void	*mem_c;

	mem_c = ft_memchr(src, c, n);
	if (mem_c != NULL)
		n = ((unsigned char)mem_c - (unsigned char)src);
	ft_memcpy(dest, src, n);
	if (mem_c == NULL)
		return (NULL);
	else
		return ((void *)(((unsigned char *)mem_c) + 1));
}