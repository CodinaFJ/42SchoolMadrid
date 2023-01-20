/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmunoz <tmunoz@student.42madrid.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:15:10 by tmunoz            #+#    #+#             */
/*   Updated: 2022/11/06 16:18:56 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_putchar(char pixel);

void	rush(int x, int y)
{
	int		i[2];

	i[0] = 1;
	i[1] = 1;
	while (i[0] <= y)
	{
		while (i[1] <= x)
		{
			if ((i[0] == 1 || i[0] == y) && (i[1] == 1 || i[1] == x))
				ft_putchar('o');
			else if (i[0] == 1 || i[0] == y)
				ft_putchar('-');
			else if (i[1] == 1 || i[1] == x)
				ft_putchar('|');
			else
				ft_putchar(' ');
			++i[1];
		}
		if (x > 0)
			ft_putchar('\n');
		++i[0];
		i[1] = 1;
	}
}
