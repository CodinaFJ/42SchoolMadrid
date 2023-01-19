/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:21:16 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/07 16:44:47 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
//#include<string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	int				src_ended;

	i = 0;
	src_ended = 0;
	while (i < n)
	{
		if (src_ended == 0)
			dest[i] = src[i];
		else
			dest[i] = 0;
		if (src[i] == 0)
			src_ended = 1;
		i++;
	}
	return (dest);
}

/*int	main(void)
{
	char	str1[6] = "abcdef";
	char	str2[6] = "abcdef";
	char	str3[4] = "1";

	ft_strncpy(str1, str3, 6);
	strncpy(str2, str3, 6);
	write(1, str1, 6);
	write(1, "\n", 1);
	write(1, str2, 6);
	write(1, "\n", 1);
}*/
