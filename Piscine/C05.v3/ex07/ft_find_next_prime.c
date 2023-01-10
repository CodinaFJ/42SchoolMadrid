/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:43:41 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/15 17:43:43 by jcodina-         ###   ########.fr       */
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
	if (nb <= 0)
		return (0);
	return (sqrt_search(0, nb, nb));
}

int	ft_check_if_prime(int nb, int i)
{
	if (i == 1)
		return (1);
	else if (nb % i == 0)
		return (0);
	else
		return (ft_check_if_prime(nb, i - 1));
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 1)
		return (2);
	if (ft_check_if_prime(nb, ft_sqrt(nb)))
		return (nb);
	return (ft_find_next_prime (nb + 1));
}

int main(void)
{
    printf("%d\n", ft_find_next_prime(2147483642));
    return (0);
}
