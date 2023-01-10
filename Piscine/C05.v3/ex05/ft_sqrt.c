/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:11:44 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/15 17:12:08 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>

int	sqrt_search(long low, long high, long nb)
{
	long	mid;

	mid = (low + high) / 2;
	if (low <= high)
	{
		if ((mid * mid <= nb) && ((mid + 1) * (mid + 1) > nb))
			return (mid);
		else if (mid * mid < nb)
			return (sqrt_search(mid + 1, high, nb));
		else
			return (sqrt_search(low, mid - 1, nb));
	}
	return (low);
}

int	ft_sqrt(int nb)
{
	int	guess;

	if (nb <= 0)
		return (0);
	guess = sqrt_search(0, nb, nb);
	if (guess * guess == nb)
		return (guess);
	else
		return (0);
}

// int main(void)
// {
//     printf("%d\n", ft_sqrt(2147483646));
//     printf("%d\n", ft_sqrt(546811456));
//     printf("%d\n", ft_sqrt(1033218904));
//     printf("%d\n", ft_sqrt(1872639076));
//     printf("%d\n", ft_sqrt(1240324401));
//     printf("%d\n", ft_sqrt(669101689));
//     printf("%d\n", ft_sqrt(1358692367));
//     printf("%d\n", ft_sqrt(767290000));
//     printf("%d\n", ft_sqrt(448909636));
//     printf("%d\n", ft_sqrt(2087850249));
//     printf("%d\n", ft_sqrt(1112637263));
// }
