/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:42:39 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/08 21:14:08 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>

void	ft_get_non_printable_char(int ascii)
{
	char	c[3];
	int		div;
	int		rest;

	div = ascii / 16;
	rest = ascii % 16;
	if (div > 9)
		div += 39;
	if (rest > 9)
		rest += 39;
	c[0] = '\\';
	c[1] = '0' + div;
	c[2] = '0' + rest;
	write(1, c, 3);
}

void	ft_putstr_non_printable(unsigned char *str)
{
	int		i;

	i = 0;
	while (*(str + i) != 0)
	{
		if (*(str + i) < 32 || *(str + i) > 127)
			ft_get_non_printable_char(*(str + i));
		else
			write(1, str + i, 1);
		i++;
	}
}

int	main(void)
{
	char c;
	char *p;
	
	ft_putstr_non_printable("ç");
	write(1, "\n", 1);
	return (0);
}
