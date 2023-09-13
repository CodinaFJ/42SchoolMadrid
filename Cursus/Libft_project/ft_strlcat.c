/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:09:53 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/27 19:49:26 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * Appends the string src to the end of the string dest.
 * String dest must have enough space to hold the result.
 * Grants null termination. Safer than strcat and strncat.
 * @param dest string to fill.
 * @param src string to append.
 * @param size buffer size of dest.
 * @return Total length of the string tried to create
 */
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	dest_len = ft_strlen(dest);
	if (size <= dest_len)
		return (size + src_len);
	i = dest_len;
	while (src[i - dest_len] && i < size)
	{
		dest[i] = src[i - dest_len];
		i++;
	}
	if (size == i)
		dest[size - 1] = '\0';
	else
		dest[i] = '\0';
	if (size < dest_len)
		return (size + src_len);
	return (dest_len + src_len);
}
