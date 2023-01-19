/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:09:28 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/07 17:11:13 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_str_is_lowercase(char *str)
{
	int		i;
	int		alpha;

	i = 0;
	alpha = 1;
	while (*(str + i) != 0)
	{
		if (!(*(str + i) > 96 && *(str + i) < 123))
			alpha = 0;
		i++;
	}
	return (alpha);
}
