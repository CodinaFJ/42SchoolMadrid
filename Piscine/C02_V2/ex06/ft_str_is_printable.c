/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:13:50 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/08 13:53:23 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_str_is_printable(char *str)
{
	int		i;
	int		alpha;

	i = 0;
	alpha = 1;
	while (*(str + i) != 0)
	{
		if (!(*(str + i) > 31 && *(str + i) <= 127))
			alpha = 0;
		i++;
	}
	return (alpha);
}

/*int	main(void)
{
	char	c;
	int		n;

	n = ft_str_is_printable("cosas");
	c = '0' + n;
	write(1, &c, 1);
	write(1, "\n", 1);
}*/
