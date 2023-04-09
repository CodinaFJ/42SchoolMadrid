/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:09:16 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/26 16:47:44 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * Locates first occurrence of c in string s.
 * @param s searched string.
 * @param c character to search.
 * @return Pointer to byte located, or NULL if there is no occurrence.
 */
char	*ft_strchr(const char *s, int c)
{
	return (ft_memchr(s, c, ft_strlen(s) + 1));
}
