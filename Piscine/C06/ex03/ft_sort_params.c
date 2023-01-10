/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:20:21 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/15 18:20:22 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (*(str + i) != 0)
		i++;
	return (i);
}

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

int	main(int argc, char **argv)
{
	int	i;
	int j;
	int winner;

	i = 1;
	while (i < argc)
	{
		winner = 1;
		j = i + 1;
		while (j < argc && winner != -1)
		{
			winner = ft_strcmp(argv[i], argv[j]);
			j++;
		}
		i++;
		if (winner == 1)
			write(1, argv[i], ft_strlen(argv[i]));
	}
}
