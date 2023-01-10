/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:06:33 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/17 19:06:35 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<unistd.h>
#include"ft_stock_str.h"

void	ft_putstr_cr(char *str)
{
	int		i;

	i = 0;
	while (*(str + i) != 0)
		i++;
	write(1, str, i);
	write(1, "\n", 1);
}

void	ft_putnbr_cr(int nb)
{
	char	number[10];
	int		looped_nb;
	int		index;
	int		neg;

	index = 0;
	neg = 1;
	if (nb < 0)
	{
		write(1, "-", 1);
		neg = -1;
	}
	else if (nb == 0)
		write(1, "0", 1);
	looped_nb = nb;
	while (looped_nb != 0)
	{
		number[9 - index] = '0' + (looped_nb * neg) % 10;
		looped_nb = looped_nb / 10;
		index++;
	}
	if (nb == -2147483648)
		number[9] = '8';
	write (1, &number[9 - index + 1], index);
	write (1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr_cr(par[i].str);
		ft_putnbr_cr(par[i].size);
		ft_putstr_cr(par[i].copy);
		i++;
	}
}

/*int	main(int argc,char **argv)
{
	t_stock_str *tab;

	tab = ft_strs_to_tab(argc, argv);
	ft_show_tab(tab);
	return (0);
}*/