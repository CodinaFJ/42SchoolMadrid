/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:23:53 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/11 10:24:07 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (*(str + i) != 0)
		i++;
	return (i);
}

void	ft_print_reverse_digits(int i, char *base, int *digits)
{
	while (i > 0)
	{
		write(1, &base[digits[32 - i]], 1);
		i--;
	}
}

int	ft_correct_nbr(long nbr)
{
	if (nbr < 0)
	{
		nbr = -nbr;
		write(1, "-", 1);
	}
	else if (nbr == 0)
	{
		write(1, "0", 1);
	}
	return (nbr);
}

int	ft_correct_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (*base == '\0' || *(base + 1) == '\0')
		return (0);
	while (*(base + i) != '\0')
	{
		if (*(base + i) == '+' || *(base + i) == '-')
			return (0);
		while (*(base + j) != '\0')
		{
			if (i != j && *(base + i) == *(base + j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				i;
	int				size;
	int				digits[32];
	unsigned int	num;

	i = 0;
	size = 0;
	if (ft_correct_base(base) == 0)
		return ;
	num = ft_correct_nbr(nbr);
	while (num > 0)
	{
		digits[31 - i] = num % ft_strlen(base);
		num = num / ft_strlen(base);
		i++;
	}
	ft_print_reverse_digits(i, base, digits);
}

int	main(void)
{
	ft_putnbr_base(-1, "0123456789abcdef");
	write(1, "\n", 1);
	return (0);
}