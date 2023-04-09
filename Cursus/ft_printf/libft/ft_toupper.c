/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:27:31 by jcodina-          #+#    #+#             */
/*   Updated: 2023/02/08 09:46:40 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * Converts a lower-case letter to the corresponding upper-case letter.
 */
int	ft_toupper(int c)
{
	if (c >= (int) 'a' && c <= (int) 'z')
		return (c - 32);
	return (c);
}
