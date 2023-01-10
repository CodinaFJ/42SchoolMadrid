/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 02:52:35 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/09 03:18:12 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>

int	ft_remove_blanks(char *str)
{
	int		i;

	i = 0;
	while (*(str + i) == '\t' || *(str + i) == '\n'
		|| *(str + i) == '\v' || *(str + i) == '\f'
		|| *(str + i) == '\r' || *(str + i) == ' ')
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int		neg;
	int		i;
	int		num;
	int		is_num;

	neg = 1;
	i = ft_remove_blanks(str);
	num = 0;
	is_num = 0;
	while (*(str + i) != 0)
	{
		if (*(str + i) >= '0' && *(str + i) <= '9')
		{
			num = (num * 10) + (*(str + i) - '0');
			is_num = 1;
		}
		else if (is_num == 1
			&& (!(*(str + i) >= '0' && *(str + i) <= '9') || *(str + i) != '+'))
			return (num * neg);
		else if (*(str + i) == '-' && is_num == 0)
			neg = neg * -1;
		i++;
	}
	return (num * neg);
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
}*/

/*int	main(int argc, char **argv)
{
	(void) 	argc;
	(void)	argv;
	int		num1;
	int		num2;

	num1 = ft_atoi(argv[1]);
	num2 = atoi(argv[1]);
	ft_putnbr(num1);
	write(1, "\n", 1);
	ft_putnbr(num2);
	write(1, "\n", 1);
	return (0);
}*/
