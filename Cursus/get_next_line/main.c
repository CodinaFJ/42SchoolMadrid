/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:13:13 by jcodina-          #+#    #+#             */
/*   Updated: 2023/02/27 20:17:48 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

int	main(int argc, char **argv)
{
	char	*line;
	int		fd;

	fd = open(argv[1], O_RDWR);
	if (fd == -1)
	{
		printf("Error open file");
		return (-1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	free(line);
	return (0);
}
