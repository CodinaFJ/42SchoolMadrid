#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*x;

	x = (unsigned char *)malloc(n * sizeof(char));
	ft_memcpy(x, src, n);
	ft_memcpy(dest, x, n);
	free(x);
	return (dest);
}