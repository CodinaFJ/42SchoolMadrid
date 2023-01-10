/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:57:39 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/21 16:57:41 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BSQ_H
# define BSQ_H
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "ft.h"
# define ERROR "map error\n"
# define ERROR_DBG "ErrorDBG\n"

typedef struct s_map_info
{
	int		size;
	int		row_len;
	char	empty;
	char	obs;
	char	full;
}				t_map_info;

typedef struct s_pos
{
	int	x;
	int	y;
	int	max;
}				t_pos;

typedef struct s_loop_vars
{
	char	c;
	char	*str;
	int		j;
	int		re;
}				t_loop_vars;

int		fill_map_info(t_map_info *map_info, char *path);
char	**build_subj_mtrx(int fd, t_map_info *map_info);
int		checkerr_size(char *path, t_map_info *map_info);
int		checkerr_charsrow(char *row, t_map_info *mi);
void	free_end(char *path, int argc);
void	free_mtrx(char **mtrx, t_map_info *map_info);
void	free_mtrx_fail(void **mtrx, int size);
void	print_map_info(t_map_info *map_info);
void	print_matrix(char **matrix, t_map_info *map_info);
void	print_matrix_int(int **matrix, t_map_info *map_info);
int		**build_extended_mtrx(t_map_info *map_info, char **subj_mtrx);
int		**fill_extended_mtrx(char **subj_mtrx, int **extended_mtrx,
			t_map_info *map_info);
t_pos	find_sol(int **extended_matrix, t_map_info *map_info);
void	solver(t_pos *sol, t_map_info *map_info, char **subj_mtrx);
void	free_mtrx_int(int **mtrx, t_map_info *map_info);
int		check_charsdiff(t_map_info *mi);
void	free_arrs(void *arr1, void *arr2);

#endif
