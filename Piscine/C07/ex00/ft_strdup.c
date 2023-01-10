/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:00:07 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/16 17:00:09 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (*(str + i) != 0)
		i++;
	return (i);
}

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

char	*ft_strdup(char *src)
{
	char	*p;

	p = malloc((ft_strlen(src) + 1) * sizeof(char));
	ft_strcpy(p, src);
	return (p);
}

// int	main(void)
// {
// 	char	*des;
// 	char	*des2;
// 	des = ft_strdup("Hola");
// 	des2 = strdup("Hola");
// 	printf("%s\n", des);
// 	printf("%s\n", des2);
// 	return (0);
// }
