/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 13:46:45 by jcodina-          #+#    #+#             */
/*   Updated: 2023/04/09 12:54:03 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	printf_str(char *var)
{
	if (!var)
		return (ft_putstrlen_fd("(null)", 1));
	return (ft_putstrlen_fd(var, 1));
}
