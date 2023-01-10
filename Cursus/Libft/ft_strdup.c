#include "libft.h"

char *ft_strdup(const char *s)
{
	char	*dup;

	dup = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (dup == NULL)
	{
		free(dup);
		errno = ENOMEM;
		return (NULL);
	}
	ft_memcpy(dup, s, ft_strlen(s) + 1);
	return (dup);
}