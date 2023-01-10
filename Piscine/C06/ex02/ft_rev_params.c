/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:16:22 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/15 18:16:25 by jcodina-         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		write(1, argv[argc - 1 - i], ft_strlen(argv[argc - 1 - i]));
		write(1, "\n", 1);
		i++;
	}
}
