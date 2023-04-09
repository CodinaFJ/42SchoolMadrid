/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:45:54 by jcodina-          #+#    #+#             */
/*   Updated: 2023/04/08 20:31:26 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * Sends string s to file descriptor fd.
 * @param c String to send.
 * @param fd File descriptor to send character.
 */
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write(fd, s, i);
}

/**
 * Sends string s to file descriptor fd. Returns length
 * @param c String to send.
 * @param fd File descriptor to send character.
 * @return length
 */
int	ft_putstrlen_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write(fd, s, i);
	return (i);
}
