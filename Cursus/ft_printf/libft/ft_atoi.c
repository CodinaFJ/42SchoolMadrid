/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:04:37 by jcodina-          #+#    #+#             */
/*   Updated: 2023/02/08 09:49:51 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int static	ft_isspace(int c)
{
	if ((unsigned char) c == ' ' || (unsigned char) c == '\t'
		|| (unsigned char) c == '\n' || (unsigned char) c == '\r'
		|| (unsigned char) c == '\v' || (unsigned char) c == '\f')
		return (1);
	return (0);
}

/**
 * Converts the initial portion of the string pointed to by str 
 * to int. Spaces at the beginning of string are ignored.
 * Takes into consideration negative numbers
 * @param nptr string to translate to int
 * @return int result of the conversion
*/
int	ft_atoi(const char *nptr)
{
	size_t	i;
	char	neg;
	int		num;

	i = 0;
	neg = 0;
	num = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (*(nptr + i) == '-' || *(nptr + i) == '+')
	{
		neg = *(nptr + i);
		i++;
	}
	while (ft_isdigit((int)*(nptr + i)))
	{
		num = (num * 10) + (int)(*(nptr + i) - '0');
		i++;
	}
	if (neg == '-')
		return (-num);
	return (num);
}
