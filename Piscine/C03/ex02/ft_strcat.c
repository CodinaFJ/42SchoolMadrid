/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:13:09 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/08 22:29:08 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<string.h>

char	*ft_strcat(char *dest, char *src)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (*(dest + i) != 0)
		i++;
	while (*(src + j) != 0)
	{
		*(dest + i + j) = *(src + j);
		j++;
	}
	*(dest + i + j) = 0;
	return (dest);
}

int main(void)
{
    char    str1[200] = "UOgSKIvCfZw";
    char    str2[200] = "UOgSKIvCfZw";
	char	str3[] = "wfsoFHKZyS";
    int     n;
    char    c;
    char    d;

    n = 4;
    ft_strcat(str1, str3);
    strcat(str2, str3);
    write(1, str1, sizeof(str1));
    write(1, "\n", 1);
    write(1, str2, sizeof(str2));
    write(1, "\n", 1);
    return(0);
}
