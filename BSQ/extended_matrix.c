/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extended_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:56:26 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/23 13:31:30 by mavintil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
*	extended_matrix.c
*
* 	Functions for building the extended matrix.
*/

#include"bsq.h"

int	**build_extended_mtrx(t_map_info *map_info, char **subj_mtrx)
{
	int	i;
	int	**mat;

	(void) subj_mtrx;
	mat = (int **)malloc(sizeof(int *) * (map_info->size + 1));
	i = 0;
	while (i < map_info->size + 1)
	{
		mat[i] = (int *)malloc(sizeof(int) * (map_info->row_len));
		i++;
	}
	return (mat);
}

void	setup_mtrx(char **subj_mtrx, int **extended_mtrx, t_map_info *map_info)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_info->size)
	{
		j = 0;
		while (j < map_info->row_len - 1)
		{
			if (subj_mtrx[i][j] == map_info->obs)
				extended_mtrx[i + 1][j + 1] = 0;
			else if (subj_mtrx[i][j] == map_info->empty)
			{
				extended_mtrx[i + 1][j + 1] = check_min(extended_mtrx[i][j],
						extended_mtrx[i][j + 1], extended_mtrx[i + 1][j]);
			}
			j++;
		}
		i++;
	}
}

int	**fill_extended_mtrx(char **subj_mtrx, int **ext_mtrx, t_map_info *map_info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < map_info->row_len)
	{
		ext_mtrx[0][j] = 0;
		j++;
	}
	while (i < map_info->size + 1)
	{
		ext_mtrx[i][0] = 0;
		i++;
	}
	setup_mtrx(subj_mtrx, ext_mtrx, map_info);
	return (ext_mtrx);
}
