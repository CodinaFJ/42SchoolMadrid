/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 01:47:30 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/09 02:09:48 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<string.h>
#include<stdio.h>

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (*(str + i) != 0)
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	int				size_dest;
	int				size_src;

	j = 0;
	size_dest = ft_strlen(dest);
	size_src = ft_strlen(src);
	if (size == 0)
		return (size_src);
	i = size_dest;
	while (*(src + j) != 0 && (i + j) < (size - 1))
	{
		*(dest + i + j) = *(src + j);
		j++;
	}
	*(dest + i + j) = 0;
	if (size_dest < size)
		return (size_dest + size_src);
	else
		return (size + size_src);
}

/*int main(void)
{
    char    str1[10] = "123456";
    char    str2[10] = "123456";
    char    str3[5] = "ad";
    char    c;
    char    d;

    c = '0' + ft_strlcat(str1, str3, 7);
    d = '0' + strlcat(str2, str3, 7);
    write(1, str1, ft_strlen(str1) + 1);
	write(1, "|  ", 3);
	write(1, &c, 1);
    write(1, "\n", 1);
    write(1, str2, ft_strlen(str2) + 1);
	write(1, "|  ", 3);
    write(1, &d, 1);
    write(1, "\n", 1);
    return(0);
}*/
