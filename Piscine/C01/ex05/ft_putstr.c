/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:08:08 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/08 17:48:38 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0)
		i++;
	write(1, str, i);
}

/*int	main(void)
{
	char	mistring[] = "Esto es un string";

	ft_putstr(mistring);
	return (0);
}*/
