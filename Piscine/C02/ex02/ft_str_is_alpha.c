/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:54:03 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/07 17:06:17 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_str_is_alpha(char *str)
{
	int		i;
	int		alpha;

	i = 0;
	alpha = 1;
	while (*(str + i) != 0)
	{
		if (!((*(str + i) > 64 && *(str + i) < 91)
				|| (*(str + i) > 96 && *(str + i) < 123)))
			alpha = 0;
		i++;
	}
	return (alpha);
}

/*int	main(void)
{
	char	c;
	int		n;

	n = ft_str_is_alpha("{");
	c = '0' + n;
	write(1, &c, 1);
	write(1, "\n", 1);
}*/
