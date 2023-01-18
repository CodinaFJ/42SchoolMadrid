/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:07:44 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/10 16:07:45 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * Uppercase character test.
*/
int	ft_isupper(int c)
{
	if (c >= (int) 'A' && c <= (int) 'Z')
		return (1);
	return (0);
}
