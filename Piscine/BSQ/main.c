/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:48:31 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/21 18:48:33 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
*	main.c
*
*	Main file.
*/

#include"bsq.h"

int	get_map_path(int argc, char *argvstr, char **path_in)
{
	*path_in = malloc(50 + 1);
	if (argc == 1)
	{
		**path_in = '\0';
		free(*path_in);
	}
	else
	{
		free(*path_in);
		*path_in = argvstr;
		if (**path_in == '\0')
			return (-1);
	}
	return (0);
}

int	setup(char *path)
{
	char		**subj_mtrx;
	int			**extended_mtrx;
	t_map_info	map_info;
	int			fd;
	t_pos		sol;

	fd = fill_map_info(&map_info, path);
	if (fd == -1)
		return (-1);
	if (map_info.size == -1 || map_info.size == 0 || check_charsdiff(&map_info))
		return (-1);
	subj_mtrx = build_subj_mtrx(fd, &map_info);
	if (!subj_mtrx)
		return (-1);
	extended_mtrx = build_extended_mtrx(&map_info, subj_mtrx);
	extended_mtrx = fill_extended_mtrx(subj_mtrx, extended_mtrx, &map_info);
	sol = find_sol(extended_mtrx, &map_info);
	free_mtrx_int(extended_mtrx, &map_info);
	solver(&sol, &map_info, subj_mtrx);
	print_matrix(subj_mtrx, &map_info);
	free_mtrx(subj_mtrx, &map_info);
	return (1);
}

int	sqr_algorithm(int argc, char **argv, char *path, int *i)
{
	if (get_map_path(argc, argv[*i], &path) == -1)
	{
		*i = *i + 1;
		ft_putstr(ERROR);
		return (-1);
	}
	if (setup(path) == -1)
	{
		*i = *i + 1;
		ft_putstr(ERROR);
		return (-1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	*path;
	int		i;

	i = 1;
	(void) argc;
	(void) argv;
	path = NULL;
	if (argc == 1)
		i = 0;
	while (i < argc)
	{
		if (sqr_algorithm(argc, argv, path, &i) == -1)
			continue ;
		i++;
	}
	free_end(path, argc);
	return (0);
}
