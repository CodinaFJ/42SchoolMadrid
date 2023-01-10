/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 02:50:39 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/24 02:50:40 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (*(str + i) != 0)
		i++;
	write(1, str, i);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	c;
	int		re;

	c = '0';
	re = 1;
	fd = open("argv[1]", O_RDONLY);
	if(fd == -1)
		ft_putstr("Cannot read file.");
	if(argc == 1)
		ft_putstr("File name missing.");
	else if(argc > 2)
		ft_putstr("Too many arguments.");
	while(re != 0)
	{	
		re = read(fd, &c, 1);
		if(re == -1)
		{
			ft_putstr("Cannot read file.");
			return (-1);
		}
		write(1, &c, 1);
	}
	return (0);
}
