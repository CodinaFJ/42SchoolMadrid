/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:46:48 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/07 16:53:30 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
//#include<string.h>

char	*ft_strcpy(char *dest, char *src)
{
	int		i;

	i = 0;
	while (*(src + i) != 0)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = *(src + i);
	return (dest);
}

/*int	main(void)
{
	char str1[10] = "abcdef";
	char str2[10] = "abcdef";
	char str3[10] = "123";

	write(1, ft_strcpy(str1, str3), 10);
	write(1, "\n", 1);
	write(1, strcpy(str2, str3), 10);
	write(1, "\n", 1);
}*/
