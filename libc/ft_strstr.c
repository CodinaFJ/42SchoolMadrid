#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*s;
	int		cmp;

	if (*needle == '\0')
		return (haystack);
	s = haystack;
	while (s != NULL)
	{
		s = strchr(haystack, (int) *needle); 
		if (ft_memcmp(s, needle, ft_strlen(needle)) == 0)
			return (s);
	}
	return (s);
}