#include "libft.h"

//I hesitate if len applies to needle or haystack. Right now it is applied to needle, because I am lazy and it was easier (I think it makes more sense for it to be applied to haystack)
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*s;
	int		cmp;

	if (*needle == '\0')
		return (haystack);
	s = haystack;
	while (s != NULL)
	{
		s = strchr(haystack, (int) *needle); 
		if (ft_memcmp(s, needle, len) == 0)
			return (s);
	}
	return (s);
}