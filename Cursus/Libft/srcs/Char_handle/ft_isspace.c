/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isspace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:51:01 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/13 18:51:03 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * Space character test.
 * Any of: '\\t' '\\n' '\\v' '\\f' '\\r' ' '
*/
int	ft_isspace(int c)
{
	if ((unsigned char) c == ' ' || (unsigned char) c == '\t'
		|| (unsigned char) c == '\n' || (unsigned char) c == '\r'
		|| (unsigned char) c == '\v' || (unsigned char) c == '\f')
		return (1);
	return (0);
}
