/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:33:17 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/16 14:33:19 by jcodina-         ###   ########.fr       */
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

int	ft_remove_blanks(char *str)
{
	int		i;

	i = 0;
	while (*(str + i) == '\t' || *(str + i) == '\n'
		|| *(str + i) == '\v' || *(str + i) == '\f'
		|| *(str + i) == '\r' || *(str + i) == ' ')
		i++;
	return (i);
}

int	ft_correct_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (*base == '\0' || *(base + 1) == '\0')
		return (0);
	while (*(base + i) != '\0')
	{
		if (*(base + i) == '+' || *(base + i) == '-')
			return (0);
		while (*(base + j) != '\0')
		{
			if (i != j && *(base + i) == *(base + j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_in_base(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int		neg;
	int		i;
	int		num;
	int		is_num;

	i = ft_remove_blanks(str);
	if (ft_correct_base(base) == 0)
		return (0);
	while (*(str + i) != 0)
	{
		if (ft_check_in_base(base, str[i]) == 1)
		{
			num = (num * 10) + (*(str + i) - '0');
			is_num = 1;
		}
		else if (is_num == 1
			&& (!(*(str + i) >= '0' && *(str + i) <= '9') || *(str + i) != '+'))
			return (num * neg);
		else if (*(str + i) == '-' && is_num == 0)
			neg = neg * -1;
		i++;
	}
	return (num * neg);
}
