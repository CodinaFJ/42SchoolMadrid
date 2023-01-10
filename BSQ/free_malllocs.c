/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_malllocs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:55:45 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/22 16:55:47 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
*	free_malllocs.c
*
*	Free allocated memory functions
*/

#include"bsq.h"

void	free_end(char *path, int argc)
{
	if (argc == 1)
		free(path);
}

void	free_mtrx(char **mtrx, t_map_info *map_info)
{
	int	i;

	i = 0;
	while (i < map_info->size)
	{
		free(mtrx[i]);
		i++;
	}
	free(mtrx);
}

void	free_mtrx_int(int **mtrx, t_map_info *map_info)
{
	int	i;

	i = 0;
	while (i < map_info->size + 1)
	{
		free(mtrx[i]);
		i++;
	}
	free(mtrx);
}

void	free_mtrx_fail(void **mtrx, int size)
{
	int	i;

	i = 0;
	while (i <= size)
	{
		free(mtrx[i]);
		i++;
	}
	free(mtrx);
}

void	free_arrs(void *arr1, void *arr2)
{
	free(arr1);
	free(arr2);
}
