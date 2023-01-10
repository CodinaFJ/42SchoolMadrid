/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanity_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarrete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:25:40 by pcarrete          #+#    #+#             */
/*   Updated: 2022/11/13 17:26:10 by pcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*--------------------------------------------------------------------------------------------
*	conditions_start.c
*
*	conditions_start.c se usa para inicializar la matriz de condiciones (enunciado del programa)
*
*	- sanity check(): comprueba que el enunciado tiene sentido.
*		1. Comprueba que sólo se pasen números divididos por espacios
*			Es decir, da error si el enunciado no está estructurado como "# # # #"...
*			Para comprobar que son números se usa ft_is_num que comprueba el número ASCII
*		2. Comprueba que el total de números sea múltiplo de 4 y calcula el tamaño
*			16 números -> size = 4 | 20 números -> size = 5 | 24 números -> size = 6...
*		3. Comprueba que no haya números mayor que el tamaño y que el tamaño sea 9 como max.
*			Para comprobación de números se usa la función check_conds_numbers()
*
*	- initialize_conditions(): inicializa los arrays de conditions.
*		char **conditions es un array de arrays. Se estructura de la siguiente forma (ejemplo de subject):
*			conditions
*	ColUp	|	[0] [4 3 2 1]
*	ColDown	|	[1]	[2 2 2 1]
*				---
*	RowLeft		[2]	[4 3 2 1]
*	RowRight	[3]	[2 2 2 1]
*
*	De esta forma si queremos las condiciones asociadas a:
*		columna 2 -> conditions[0][1]
*					 conditions[1][1]
*
*		fila 1	  -> conditions[2][0]
*					 conditions[3][0]
*
-----------------------------------------------------------------------------------------------*/
#include <unistd.h>
#include <stdlib.h>

int	ft_is_num( char c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

int	check_conds_numbers(char *str, int size)
{
	int	i;

	i = 0;
	while (*(str + i) != 0)
	{
		if (*(str + i) > '0' + size)
			return (0);
		i++;
	}
	return (1);
}

int	sanity_check(int argc, char **argv, int *size)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	if (argc != 2)
		return (0);
	if (argv[1][0] == 0) //Línea post entrega para gestionar string nulo.
		return (0);
	while (argv[1][i] != 0)
	{
		if (i % 2 == 0)
		{
			if (ft_is_num(argv[1][i]) == 0)
				return (0);
			else
				total++;
		}
		else if (i % 2 == 1 && argv[1][i] != ' ')
			return (0);
		i++;
	}
	*size = total / 4;
	if (check_conds_numbers(argv[1], *size) != 1 || *size > 9 || total % 4 != 0)
		return (0);
	return (1);
}

char	**initialize_conditions(char **conditions, char **argv, int size)
{
	int	i;

	i = 0;
	conditions = malloc(4 * sizeof (char *));
	while (i < 4)
	{
		conditions[i] = malloc(size * sizeof (char));
		i++;
	}
	i = 0;
	while (argv[1][i] != 0)
	{
		if (i % 2 == 0)
			conditions[(i / 2) / size][(i / 2) % size] = argv[1][i];
		i++;
	}
	return (conditions);
}
