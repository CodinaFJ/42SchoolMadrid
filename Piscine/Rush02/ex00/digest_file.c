/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digest_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:44:28 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/20 18:44:30 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include"ft.h"
#include"rush02.h"

int	*calc_size_rows(char *file_text, int rows)
{
	int	*size_rows;
	int	i;
	int	j;

	i = 0;
	j = 0;
	size_rows = malloc(rows * sizeof(int));
	while (*file_text)
	{
		i++;
		if (*file_text == '\n')
		{
			size_rows[j] = i;
			j++;
			i = 0;
		}
		file_text++;
	}
	return (size_rows);
}

int	calc_buffer(char *path)
{
	int		fd;
	int		buf_size;
	char	buf_search[2];

	buf_size = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (read(fd, buf_search, 1))
		buf_size++;
	close(fd);
	return (buf_size);
}

int	read_file(char *path, int buf_size, char **file_text)
{
	int		fd;
	int		rev;

	if (buf_size == -1)
		return (-1);
	*file_text = malloc((buf_size + 1) * sizeof(char));
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		free(*file_text);
		return (-1);
	}
	rev = read(fd, *file_text, buf_size);
	(*file_text)[rev] = '\0';
	close(fd);
	return (1);
}
