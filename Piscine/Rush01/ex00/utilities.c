/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:46:34 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/13 18:46:36 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*--------------------------------------------------------------------------------------------
*	utilities.c
*
*	Contiene funciones varias que necesitamos llamar desde otros sitios.
*
*	- get_size(): devuelve el tamaño del cuadrado a resolver
*
*	- get_column(): devuelve un array con los número de la columna (col) que se le especifique
*
*	- print_box(): saca por pantalla los números calculados del cuadrado
*
-----------------------------------------------------------------------------------------------*/
#include <unistd.h>
#include <stdlib.h>

int	get_size(char **box)
{
	int	i;

	i = 0;
	while (box[i] != 0)
		i++;
	return (i);
}

char	*get_column(char **box, int size, int col)
{
	int		i;
	char	*column_array;

	column_array = malloc(size * sizeof(char));
	i = 0;
	while (i < size)
	{
		column_array[i] = box[i][col];
		i++;
	}
	return (column_array);
}

void	print_box(char **box)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < get_size(box))
	{
		while (j < get_size(box))
		{
			write(1, &box[i][j], 1);
			if (j != get_size(box) - 1)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
		j = 0;
	}
}
