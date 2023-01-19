/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:11:47 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/07 17:12:58 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_str_is_uppercase(char *str)
{
	int		i;
	int		alpha;

	i = 0;
	alpha = 1;
	while (*(str + i) != 0)
	{
		if (!(*(str + i) > 64 && *(str + i) < 91))
			alpha = 0;
		i++;
	}
	return (alpha);
}
