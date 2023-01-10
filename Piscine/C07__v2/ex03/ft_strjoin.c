/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:18:49 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/16 17:18:50 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (*(str + i) != 0)
		i++;
	return (i);
}

int	ft_get_size(int size, char **strs, char *sep)
{
	int	size_total;
	int	i;

	size_total = 0;
	i = 0;
	while (i < size)
	{
		size_total += ft_strlen(strs[i]);
		i++;
	}
	size_total += (size - 1) * ft_strlen(sep);
	return (size_total);
}

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

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		i;
	int		total_size;

	i = 0;
	total_size = ft_get_size(size, strs, sep) + 1;
	if (size == 0)
		return (malloc(0 * sizeof(char)));
	str = malloc(total_size * sizeof(char));
	if (str == NULL)
		return (0);
	while (i < size)
	{
		ft_strcat(str, strs[i]);
		i++;
		if (i < size)
			ft_strcat(str, sep);
	}
	str[total_size] = '\0';
	return (str);
}

// int	main(int argc, char **argv)
// {
// 	printf("%s\n", ft_strjoin(argc, argv, "||"));
// 	return (0);
// }
