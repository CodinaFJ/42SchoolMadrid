/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:13:43 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/21 19:13:45 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
*	prints.c
*
*	Utilities to print stuff.
*/

#include"bsq.h"

void	print_matrix(char **matrix, t_map_info *map_info)
{
	int	i;

	i = 0;
	while (i < map_info->size)
	{
		ft_putstr(matrix[i]);
		i++;
	}
}

void	print_matrix_int(int **matrix, t_map_info *map_info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map_info->size + 1)
	{
		while (j < map_info->row_len)
		{
			ft_putnbr(matrix[i][j]);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
		j = 0;
	}
}

void	print_map_info(t_map_info *map_info)
{
	ft_putstr("Size is: ");
	ft_putnbr(map_info->size);
	ft_putstr("\n");
	ft_putstr("Row_len is: ");
	ft_putnbr(map_info->row_len);
	ft_putstr("\n");
	ft_putstr("Chars are: ");
	write(1, &(map_info->empty), 1);
	write(1, &(map_info->full), 1);
	write(1, &(map_info->obs), 1);
	ft_putstr("\n");
}
