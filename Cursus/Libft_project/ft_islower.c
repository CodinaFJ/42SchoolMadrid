/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:07:21 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/26 16:46:09 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * Lowercase alphabetic character test.
*/
int	ft_islower(int c)
{
	if (c >= (int) 'a' && c <= (int) 'z')
		return (1);
	return (0);
}
