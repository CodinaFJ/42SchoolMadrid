/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:13:19 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/07 14:13:26 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>

void	ft_swap(int *a, int *b)
{
	int		aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int		aux;
	int		i;

	i = 0;
	while (i < (size / 2))
	{
		ft_swap(tab[i], tab[size - 1 - i]);
		i++;
	}
}

int	main(void)
{
	int intarray[] = {1, 2, 3};

	ft_rev_int_tab(intarray, 3);
	printf("%d, %d, %d\n", intarray[0], intarray[1], intarray[2]);
	return (0);
}