/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:38:56 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/17 18:38:58 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>
#include"ft_stock_str.h"

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (*(str + i) != 0)
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int		i;

	i = 0;
	while (*(src + i) != 0)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}

void	free_tab_fail(t_stock_str *tab, int i)
{
	int	j;

	j = 0;
	while (i < j)
		free(tab[j].copy);
	free(tab);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*tab;

	i = 0;
	tab = malloc((ac + 1) * sizeof(t_stock_str));
	while (i < ac)
	{
		tab[i].size = ft_strlen(av[i]);
		tab[i].str = av[i];
		tab[i].copy = malloc((ft_strlen(av[i]) + 1) * sizeof(char));
		if (tab[i].copy == NULL)
		{
			free_tab_fail(tab, i);
			return (NULL);
		}
		tab[i].copy = ft_strcpy(tab[i].copy, av[i]);
		i++;
	}
	tab[ac].size = 0;
	tab[ac].str = NULL;
	tab[ac].copy = NULL;
	return (tab);
}
