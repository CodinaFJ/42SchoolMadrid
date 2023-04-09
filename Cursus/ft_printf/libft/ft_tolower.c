/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:30:33 by jcodina-          #+#    #+#             */
/*   Updated: 2023/02/08 09:46:51 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * Converts a upper-case letter to the corresponding lower-case letter.
 */
int	ft_tolower(int c)
{
	if (c >= (int) 'A' && c <= (int) 'Z')
		return (c + 32);
	return (c);
}
