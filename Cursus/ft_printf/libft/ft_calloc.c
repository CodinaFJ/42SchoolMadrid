/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:09:39 by jcodina-          #+#    #+#             */
/*   Updated: 2023/02/09 16:24:31 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * Contiguously allocates enough space for count objects that are size bytes
 * of memory each and returns a pointer to the allocated memory.
 * The allocated memory is filled with bytes of value zero.
 * @param count number of objects.
 * @param size bytes of each objects.
 * @return Pointer to alllocated memory. NULL is allocation fails.
 */
void	*ft_calloc(size_t count, size_t size)
{
	void	*s;

	s = malloc(count * size);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, count * size);
	return (s);
}
