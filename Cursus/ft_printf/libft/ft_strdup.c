/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:09:46 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/26 17:31:18 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * Allocates sufficient memory for a copy of the string s,
 * does the copy, and returns a pointer to it
 * @param s string to copy.
 * @return Pointer to allocated string.
 */
char	*ft_strdup(const char *s)
{
	char	*dup;

	dup = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	ft_memcpy(dup, s, ft_strlen(s) + 1);
	return (dup);
}
