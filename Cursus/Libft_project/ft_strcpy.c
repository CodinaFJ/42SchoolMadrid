/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:09:37 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/26 16:47:50 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * Copy string src to dest
 * @param dest string to fill
 * @param src string to copy
 * @return dest
 */
char	*ft_strcpy(char *dest, const char *src)
{
	ft_memcpy(dest, src, ft_strlen(src) + 1);
	return (dest);
}
