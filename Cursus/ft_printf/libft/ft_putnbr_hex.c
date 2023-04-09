/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 13:58:16 by jcodina-          #+#    #+#             */
/*   Updated: 2023/04/09 17:39:30 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Transforms number nbr to hexadecimal and sends it to standard output.
 * @param nbr Number to transform and print.
 * @param hex_type LOWER_HEX to print in lowercase. UPPER_HEX to print in 
 * uppercase.
 * @return Number of printed characters.
 */
int	ft_putnbrlen_hex(long long nbr, int hex_type)
{
	int	size;

	if (nbr < 0)
		nbr = nbr + UINT32_MAX + 1;
	if (hex_type == LOWER_HEX)
		size = ft_putnbrlen_base(nbr, "0123456789abcdef");
	else if (hex_type == UPPER_HEX)
		size = ft_putnbrlen_base(nbr, "0123456789ABCDEF");
	else
		return (ft_putnbrlen_hex(nbr, LOWER_HEX));
	return (size);
}
