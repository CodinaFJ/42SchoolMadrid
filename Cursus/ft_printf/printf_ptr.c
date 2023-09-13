/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 13:46:45 by jcodina-          #+#    #+#             */
/*   Updated: 2023/04/09 17:17:40 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	printf_ptr(long long var)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	len += printf_hex_low((long long)var);
	return (len);
}
