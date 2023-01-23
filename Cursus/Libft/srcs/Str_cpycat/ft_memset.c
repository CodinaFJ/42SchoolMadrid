/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:08:51 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/10 16:08:53 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * Write len bytes of value c (converted to unsigned char) starting at s
 * @param s Starting memory address
 * @param c Byte to copy (converted to unsigned char)
 * @param len Number of bytes to write
 * @return Returns first argument
*/
void	*ft_memset(void *s, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (*(((unsigned char *)s) + i) != (unsigned char)c)
			*(((unsigned char *)s) + i) = (unsigned char)c;
		i++;
	}
	return (s);
}
