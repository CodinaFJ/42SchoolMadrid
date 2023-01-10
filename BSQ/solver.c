/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:12:22 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/23 15:12:23 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
*	solver.c
*
*	File with functions that find the biggest square and print it.
*
*/

#include "bsq.h"

t_pos	find_sol(int **extended_matrix, t_map_info *map_info)
{
	t_pos	sol;
	t_pos	iter;

	sol.max = 0;
	iter.x = 0;
	while (iter.x < map_info->size + 1)
	{
		iter.y = 0;
		while (iter.y < map_info->row_len)
		{
			if (extended_matrix[iter.x][iter.y] > sol.max)
			{
				sol.max = extended_matrix[iter.x][iter.y];
				sol.x = iter.x - 1;
				sol.y = iter.y - 1;
			}
			iter.y++;
		}
		iter.x++;
	}
	return (sol);
}

void	solver(t_pos *sol, t_map_info *map_info, char **subj_mtrx)
{
	int	count1;
	int	count2;

	count1 = sol->x - (sol->max - 1);
	count2 = sol->y - (sol->max - 1);
	while (count1 <= sol->x)
	{
		count2 = sol->y - (sol->max - 1);
		while (count2 <= sol->y)
		{
			subj_mtrx[count1][count2] = map_info->full;
			count2++;
		}
		count1++;
	}
}
