/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:20:28 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/21 15:20:31 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
*	ft_str.c
*
*	File with some of our basic str functions.
*/

#include "bsq.h"

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (*(str + i) != 0)
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (*(str + i) != 0)
		i++;
	write(1, str, i);
}

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
	dest[i] = 0;
	return (dest);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
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

char	*ft_rmv_cr(char *str)
{
	char	*str_cpy;
	int		i;

	i = 0;
	str_cpy = malloc((ft_strlen(str) + 1) * sizeof(char));
	while (str[i] != '\n')
	{
		str_cpy[i] = str[i];
		i++;
	}
	str_cpy[i] = '\0';
	free(str);
	return (str_cpy);
}
