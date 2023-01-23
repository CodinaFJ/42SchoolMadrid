/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:40:46 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/16 14:40:48 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * Sends character c to file descriptor fd.
 * @param c Character to send.
 * @param fd File descriptor to send character.
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
