/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:29:44 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/08 21:53:46 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
//#include<string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int		i;
	int		cmp;

	i = 0;
	cmp = 0;
	while (*(s1 + i) != 0 && cmp == 0)
	{
		if (*(s1 + i) > *(s2 + i))
			cmp = 1;
		else if (*(s1 + i) < *(s2 + i))
			cmp = -1;
		i++;
	}
	if (cmp == 0 && *(s1 + i) < *(s2 + i))
		cmp = -1;
	return (cmp);
}

int	main(void)
{
	char	c1;
	char	c2;

	c1 = '0' + ft_strcmp(" ", "0");
	c2 = '0' + strcmp(" ", "0");
	write(1, &c1, 1);
	write(1, "\n", 1);
	write(1, &c2, 1);
	write(1, "\n", 1);
	return (0);
}
