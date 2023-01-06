#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if ((unsigned char *)src + n >= (unsigned char *)dest)
		ft_memmove(dest, src, n);
	else
	{
		while(i < n)
		{
			*((unsigned char *) dest) = *((unsigned char *)src + i);
			i++;
		}
	}
	return (dest);
}