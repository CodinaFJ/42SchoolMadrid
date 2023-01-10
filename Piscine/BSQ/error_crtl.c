/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_crtl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:32:22 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/22 13:32:23 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
*	error_crtl.c
*
*	Functions to control errors in program.
*/

#include"bsq.h"

int	checkerr_size(char *path, t_map_info *map_info)
{
	int		fd;
	int		i;
	char	c;

	i = 0;
	c = '0';
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (c != '\n')
		read(fd, &c, 1);
	while (read(fd, &c, 1))
		i++;
	if (i != ((map_info->row_len + 1) * map_info->size))
		return (-1);
	return (0);
}

int	checkerr_charsrow(char *row, t_map_info *mi)
{
	while (*row)
	{
		if (*row != mi->obs && *row != mi->empty && *row != '\n')
		{
			return (-1);
		}
		row++;
	}
	return (0);
}

int	check_charsdiff(t_map_info *mi)
{
	if (mi->empty == mi->obs || mi->empty == mi->full || mi->full == mi->obs)
		return (-1);
	if (ft_char_printable(mi->empty) == -1
		|| ft_char_printable(mi->full) == -1
		|| ft_char_printable(mi->obs) == -1)
		return (-1);
	return (0);
}
