/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:03:42 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/22 18:55:33 by mavintil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
*	ft_str.c
*
*	File with some of our basic functions.
*/

#include"bsq.h"

int	check_min(int a, int b, int c)
{
	int	min;

	min = a;
	if (min > b)
	{
		min = b;
	}
	if (min > c)
	{
		min = c;
	}
	min++;
	return (min);
}

void	ft_putnbr(int nb)
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
}

void	ft_putnbr_blnk(int nb)
{
	char	number[10];
	int		looped_nb;
	int		index;
	int		neg;

	(void) number;
	index = 0;
	neg = 1;
	if (nb < 0)
	{
		neg = -1;
	}
	looped_nb = nb;
	while (looped_nb != 0)
	{
		number[9 - index] = '0' + (looped_nb * neg) % 10;
		looped_nb = looped_nb / 10;
		index++;
	}
	if (nb == -2147483648)
		number[9] = '8';
}

int	ft_atoi_n(char *str, int n)
{
	int	num;
	int	i;

	i = 0;
	num = 0;
	while (str[i] == ' ' || str[i] < 32)
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (-1);
	while ((str[i] || str[i] != '\n') && i < n)
	{
		num = (num * 10) + (*(str + i) - '0');
		i++;
	}
	return (num);
}

int	ft_char_printable(char c)
{
	if (c < 32)
		return (-1);
	return (0);
}
