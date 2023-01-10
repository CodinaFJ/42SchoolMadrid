/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:52:26 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/08 20:23:47 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<string.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	size_return;

	i = 0;
	size_return = 0;
	while (src[size_return] != 0)
		size_return++;
	while (*(src + i) != 0 && i < size - 1)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	dest[i] = '\0';
	return (size_return);
}

int	main(void)
{
	char	dest1[3] = "123";
	char	dest2[3] = "123";
	char	src1[] = "abcaaa";
	char	src2[] = "abcaaa";
	int		size1;
	int		size2;
	char	c1;
	char	c2;

	size1 = ft_strlcpy(dest1, src1, 3);
	size2 = strlcpy(dest2, src2, 3);
	c1 = size1 + '0';
	c2 = size2 + '0';
	write(1, dest1, 4);
	write(1, "   ", 1);
	write(1, &c1, 1);
	write(1, "\n", 1);
	write(1, dest2, 4);
	write(1, "   ", 1);
	write(1, &c2, 1);
	write(1, "\n", 1);
}
