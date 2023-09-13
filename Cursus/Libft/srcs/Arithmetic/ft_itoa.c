/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:37:18 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/26 15:22:49 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int static	calc_len(int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char static	*cpy_nbr(int nbr, int len, int neg)
{
	char	*str;
	int		i;

	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (prot_malloc(str));
	i = 0;
	if (nbr == 0)
		str[0] = '0';
	while (nbr != 0)
	{
		str[len - 1 - i] = neg * (nbr % 10) + '0';
		nbr = nbr / 10;
		i++;
	}
	str[len] = '\0';
	return (str);
}

/**
 * Converts the integer n to a string. The result is return in an
 * allocated string. Negative numbers are managed.
 * @param n number to translate to string.
 * @return Pointer to the allocated string with the result. NULL if allocation
 * fails
 */
char	*ft_itoa(const int n)
{
	int		len;
	int		neg;
	char	*str;

	neg = 1;
	if (n < 0)
		neg = -1;
	len = calc_len((int)n);
	if (neg == -1)
		len++;
	str = cpy_nbr((int)n, len, neg);
	if (str == NULL)
		return (NULL);
	if (neg == -1)
		str[0] = '-';
	return (str);
}
