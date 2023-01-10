/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:50:38 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/11 14:50:43 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

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

int main(int argc, char **argv)
{
    int *p;

    p = ft_range(atoi(argv[1]), atoi(argv[2]));

    for(int i = 0; i < (atoi(argv[2]) - atoi(argv[1])); i++)
    {
        printf("%d, ", p[i]);
    }
    return (0);
}
