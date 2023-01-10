/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:21:14 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/07 14:21:17 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
// #include<stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int		changes;
	int		aux;
	int		i;

	changes = 1;
	i = 0;
	while (changes > 0)
	{
		changes = 0;
		i = 0;
		while (i < size)
		{
			if (*(tab + i) > *(tab + 1 + i))
			{
				aux = *(tab + i);
				*(tab + i) = *(tab + 1 + i);
				*(tab + 1 + i) = aux;
				changes++;
			}
			i++;
		}
	}
}

int	main(void)
{
	int intarray[] = {96, 80, 0, 6, -500};

	ft_sort_int_tab(intarray, 3);
	printf("%d, %d, %d, %d\n", intarray[0], intarray[1], intarray[2], intarray[3]);
	return (0);
}
