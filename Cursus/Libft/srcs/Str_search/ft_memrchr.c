/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:42:58 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/18 11:43:02 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Locates last occurrence of c in memory area s within n bytes.
 * @param s searched memory area
 * @param c character to search
 * @param n bytes to cover in the search
 * @return pointer to byte located, or NULL if there is no occurrence
 */
void	*ft_memrchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = n - 1;
	while (i >= 0)
	{
		if ((*((unsigned char *)s + i)) == (unsigned char)c)
			return ((void *) s + i);
		i--;
	}
	return (NULL);
}
