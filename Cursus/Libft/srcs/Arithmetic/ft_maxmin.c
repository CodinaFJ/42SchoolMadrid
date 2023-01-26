/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maxmin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:27:03 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/26 15:22:51 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
/**
 * Returns the min value of two size_t variables.
 */
size_t	ft_mins(size_t n1, size_t n2)
{
	if (n1 > n2)
		return (n2);
	else
		return (n1);
}

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
