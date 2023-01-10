/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:16:47 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/08 18:14:03 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

char	*ft_strupcase(char *str)
{
	int		i;

	i = 0;
	while (*(str + i) != 0)
	{
		if (*(str + i) > 96 && *(str + i) < 123)
			*(str + i) -= 32;
		i++;
	}
	return (str);
}

/*int	main(void)
{
	char str[] = "arrIba";
	write(1, ft_strupcase(str), 6);
	write(1, "\n", 1);
	return (0);
}*/
