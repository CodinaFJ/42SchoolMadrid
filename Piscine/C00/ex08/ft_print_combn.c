/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:40:22 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/08 13:50:41 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_print_combn(int n)
{
	char	numbers[12];
	int		index;
	int		a;
	int		i;

	i = 0;
	numbers[n + 1] = ',';
	numbers[n + 2] = ' ';
	index = 0;
	a = 1;
	while (index < n)
	{
		numbers[index] = '0' + index;
		index ++;
	}
	index = n - 1;
	write(1, numbers, n + 3);
	while (index >= 0)
	{
		numbers[index]++;
		if(index == n - 1)
			write (1, numbers, n + 3);
		if (numbers[index] == '9' - ((n - 1) - index))
		{
			i = index;
			while(i < n)
			{	
				if (i == index)
					a = 2;
				else
					a = 1;
				numbers[i] = numbers[i - 1] + a;
				i++;
			}
			index--;
		}
		else if (index < n - 1)
		{
			index++;
			//numbers[index] = numbers[index - 1] + 1;
		}
	}
	write (1, numbers, n);
}

int main(void)
{
	ft_print_combn(3);
	return (0);
}
