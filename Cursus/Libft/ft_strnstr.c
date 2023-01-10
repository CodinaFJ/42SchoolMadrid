#include "libft.h"

//I hesitate if len applies to needle or haystack. Right now it is applied to haystack.
//Still, the comparison in the while loop can make get further than len and then it wouldn't work. This is a bug that MUST be fixed.
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*s;
	int		cmp;

	if (*needle == '\0')
		return (haystack);
	s = haystack;
	while (s != NULL && (int)(s - haystack) < (int)len)
	{
		s = strchr(haystack, (int)*needle); 
		if (ft_memcmp(s, needle, ft_strlen(needle)) == 0)
			return (s);
	}
	return (s);
}