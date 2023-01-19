/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:39:19 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/14 19:43:03 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	n;

	if (nb < 0)
		return (0);
	n = 1;
	while (nb > 0)
	{
		n = n * nb;
		nb--;
	}
	return (n);
}

// int	main(void)
// {
// 	printf("%d\n", ft_iterative_factorial(0));
// 	return (0);
// }
