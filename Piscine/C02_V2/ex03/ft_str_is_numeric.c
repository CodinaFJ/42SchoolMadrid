/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:06:48 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/07 17:09:03 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_str_is_numeric(char *str)
{
	int		i;
	int		num;

	i = 0;
	num = 1;
	while (*(str + i) != 0)
	{
		if (!(*(str + i) > 47 && *(str + i) < 58))
			num = 0;
		i++;
	}
	return (num);
}

/*int	main(void)
{
	char	c;
	int		n;

	n = ft_str_is_numeric(":");
	c = '0' + n;
	write(1, &c, 1);
	write(1, "\n", 1);
}*/
