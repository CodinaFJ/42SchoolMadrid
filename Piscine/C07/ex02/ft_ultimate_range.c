/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:05:42 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/16 17:05:49 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>

int	*ft_range(int min, int max)
{
	int	*p;
	int	i;

	i = 0;
	if (min > max)
		return (0x0);
	p = malloc((max - min) * sizeof(int));
	while (i < max - min)
	{
		*(p + i) = min + i;
		i++;
	}
	return (p);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;

	size = max - min;
	i = 0;
	if (min > max)
	{
		range = NULL;
		return (0);
	}
	*range = ft_range(min, max);
	return (size);
}
