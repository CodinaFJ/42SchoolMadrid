/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maxs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:49:29 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/26 16:59:34 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * Returns the max value of two size_t variables.
 */
size_t	ft_maxs(size_t n1, size_t n2)
{
	if (n1 < n2)
		return (n2);
	else
		return (n1);
}
