/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:59:35 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/08 22:12:28 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
//#include<string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	int				cmp;

	i = 0;
	cmp = 0;
	while (*(s1 + i) != 0 && cmp == 0 && i < n)
	{
		cmp = *(s1 + i) - *(s2 + i);
		i++;
	}
	if (cmp == 0 && *(s1 + i) < *(s2 + i) && i < n)
		cmp = *(s1 + i) - *(s2 + i);
	return (cmp);
}

/*void	ft_putnbr(int nb)
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

int	main(void)
{
	char	str1[] = "A239";
	char	str2[] = "A239   4";
	int		n;
	char	c;
	char	d;

	n = 5;
	ft_putnbr(ft_strncmp(str1, str2, n));
	write(1, "\n", 1);
	ft_putnbr(strncmp(str1, str2, n));
	write(1, "\n", 1);
	return(0);
}*/
