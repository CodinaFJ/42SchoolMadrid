/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:35:24 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/21 16:35:26 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
*	read_map.c
*
*	Utilities to read map.
*/

#include"bsq.h"

int	calc_buffer_1row(char *path)
{
	int		fd;
	int		buf_size;
	char	buf_search;

	buf_size = 0;
	fd = open(path, O_RDONLY);
	if (!path)
		fd = 0;
	else
		fd = open(path, O_RDONLY);
	while (read(fd, &buf_search, 1) && buf_search != '\n')
		buf_size++;
	close(fd);
	return (buf_size);
}

int	read_loop(t_loop_vars *l_vars, int fd, char **mtrx, int i)
{
	int	first;

	first = 1;
	l_vars->c = '0';
	while (l_vars->c != '\n')
	{
		l_vars->j++;
		l_vars->re = read(fd, &l_vars->c, 1);
		if (l_vars->re <= 0 || (l_vars->c == '\n' && first == 1))
		{
			free_arrs((void *)l_vars->str, (void *) mtrx[i]);
			close(fd);
			return (-1);
		}
		first = 0;
		free(l_vars->str);
		l_vars->str = ft_strncpy(malloc(l_vars->j), mtrx[i], l_vars->j - 1);
		free(mtrx[i]);
		mtrx[i] = ft_strncat(ft_strncpy(malloc((l_vars->j + 1)),
					l_vars->str, l_vars->j - 1), &(l_vars->c), 1);
	}
	return (0);
}

int	read_row(int fd, t_map_info *map_info, char **mtrx, int i)
{
	t_loop_vars	l_vars;

	l_vars.j = 0;
	l_vars.str = malloc((l_vars.j + 1) * sizeof(char));
	mtrx[i] = malloc((l_vars.j + 1) * sizeof(char));
	if (read_loop (&l_vars, fd, mtrx, i) == -1)
		return (-1);
	free(l_vars.str);
	if (i == 0 || map_info->row_len == l_vars.j)
	{
		map_info->row_len = l_vars.j;
		return (0);
	}
	else
		return (-1);
}

char	**build_subj_mtrx(int fd, t_map_info *map_info)
{
	char	**subj_mtrx;
	int		i;

	i = 0;
	subj_mtrx = malloc((map_info->size + 1) * sizeof(char *));
	while (i < (map_info->size))
	{
		if (read_row(fd, map_info, subj_mtrx, i) == -1)
		{
			free_mtrx_fail((void **)subj_mtrx, i - 1);
			return (NULL);
		}
		subj_mtrx[i][map_info->row_len] = '\0';
		ft_putnbr_blnk(i);
		if (checkerr_charsrow(subj_mtrx[i], map_info) == -1)
		{
			free_mtrx_fail((void **)subj_mtrx, i);
			return (NULL);
		}
		i++;
	}
	if (fd != 0)
		close(fd);
	return (subj_mtrx);
}

int	fill_map_info(t_map_info *map_info, char *path)
{
	int		fd;
	char	*read_info;

	if (*path == '\0')
		fd = 0;
	else
		fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	if (read_row(fd, map_info, &read_info, 0) == -1)
		return (-1);
	read_info[map_info->row_len] = '\0';
	map_info->size = ft_atoi_n(read_info, map_info->row_len - 4);
	map_info->empty = read_info[map_info->row_len - 4];
	map_info->obs = read_info[map_info->row_len - 3];
	map_info->full = read_info[map_info->row_len - 2];
	free(read_info);
	return (fd);
}
