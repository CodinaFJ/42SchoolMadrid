#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*s;
	int		cmp;
	int		n_len;

	if (*needle == '\0')
		return (haystack);
	n_len = ft_strlen(needle);
	s = haystack;
	while (s != NULL)
	{
		s = strchr(haystack, (int) *needle); 
		if (ft_memcmp(s, needle, n_len) == 0)
			return (s);
	}
	return (s);
}