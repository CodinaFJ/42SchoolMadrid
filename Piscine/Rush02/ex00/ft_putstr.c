/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:08:08 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/08 17:48:38 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include"ft.h"

void	ft_putstr(char *str, int fd)
{
	int		i;

	i = 0;
	while (*(str + i) != 0)
		i++;
	write(fd, str, i);
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

int	ft_str_is_numeric(char *str)
{
	int		i;
	int		num;

	i = 0;
	num = 1;
	while (*(str + i) != 0)
	{
		if (!(*(str + i) > 47 && *(str + i) < 58))
			num = -1;
		i++;
	}
	return (num);
}

unsigned long	*ft_sort_int_tab(unsigned long *tab, unsigned long size)
{
	unsigned long		changes;
	unsigned long		aux;
	unsigned long		i;

	changes = 1;
	i = 0;
	while (changes > 0)
	{
		changes = 0;
		i = 0;
		while (i < size - 2)
		{
			if (*(tab + i) < *(tab + 1 + i))
			{
				aux = *(tab + i);
				*(tab + i) = *(tab + 1 + i);
				*(tab + 1 + i) = aux;
				changes++;
			}
			i++;
		}
	}
	return (tab);
}
