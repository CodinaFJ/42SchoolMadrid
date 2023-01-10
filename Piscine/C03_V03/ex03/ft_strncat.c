/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:30:13 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/08 22:39:59 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<string.h>
#include<stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;
	int				src_ended;

	i = 0;
	j = 0;
	src_ended = 0;
	while (*(dest + i) != 0)
		i++;
	while (j < nb && *(src + j) != 0)
	{
		*(dest + i + j) = *(src + j);
		j++;
	}
	*(dest + i + j) = 0;
	return (dest);
}

/*int main(void)
{
    char    str1[15] = "1234567";
    char    str2[15] = "1234567";
    char    str3[] = "Metoesto";
    int     n;
    char    c;
    char    d;

    n = 6;
    ft_strncat(str1, str3, n);
    //strncat(str2, str3, n);
	write(1, str1, 15);
	write(1, "\n", 15);
	//printf("%s\n", str1);
	//printf("%s\n", str2);
    return(0);
}*/
