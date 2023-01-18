/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:34:24 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/18 10:34:26 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * Blank character test.
 * Any of: '\t' ' '
*/
int	ft_isblank(int c)
{
	if ((unsigned char) c == ' ' || (unsigned char) c == '\t')
		return (1);
	return (0);
}
