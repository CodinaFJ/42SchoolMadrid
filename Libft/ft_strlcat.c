#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;

	i = 0;
	while (dest[dest_len] != '\0')
	{
		dest_len++;
		if (dest_len >= size)
			return (size);
	}
	if (ft_strlen(src) + 1 < (size - dest_len))
		ft_strcpy(dest + dest_len, src);
	else
	{
		ft_strncpy(dest + dest_len, src, (size - dest_len) - 1);
		dest[size] = '\0';
	}
	return (dest_len + ft_strlen(src));
}