/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:43:13 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/09 01:46:08 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<string.h>

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (*to_find == 0)
		return (str);
	while (*(str + i) != 0)
	{
		if (*(str + i) == *(to_find))
		{
			while (*(str + i + j) == *(to_find + j))
			{
				j++;
				if (*(to_find + j) == 0)
					return (str + i);
			}
			j = 0;
		}
		i++;
	}
	return (NULL);
}

/*void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0)
		i++;
	write(1, str, i);
}

int	main(void)
{
	char	haystack1[] = "holaquetal";
	char	needle1[] = "olaquepasa";
	char	haystack2[] = "holaquetal";
	char	needle2[] = "olaquepasa";
	char	*str1 = ft_strstr(haystack1, needle1);
	char	*str2 = strstr(haystack2, needle2);

	ft_putstr(str1);
	write(1, "\n", 1);
	ft_putstr(str2);
	write(1, "\n", 1);
	return (0);
}*/
