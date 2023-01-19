/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:57:40 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/08 18:18:33 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

char	*ft_strlowcase(char *str)
{
	int		i;

	i = 0;
	while (*(str + i) != 0)
	{
		if (*(str + i) > 64 && *(str + i) < 91)
			*(str + i) += 32;
		i++;
	}
	return (str);
}

/*int	main(void)
{
	char	str[] = "ABAjO";

	write(1, ft_strlowcase(str), 5);
	write(1, "\n", 1);
	return (0);
}*/
