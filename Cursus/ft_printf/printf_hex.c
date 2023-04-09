/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 13:46:45 by jcodina-          #+#    #+#             */
/*   Updated: 2023/04/09 17:10:22 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_hex_low(long long var)
{
	return (ft_putnbrlen_hex(var, LOWER_HEX));
}

int	printf_hex_upp(long long var)
{
	return (ft_putnbrlen_hex(var, UPPER_HEX));
}
