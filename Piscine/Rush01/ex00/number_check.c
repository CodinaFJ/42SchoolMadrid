/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarrete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:53:56 by pcarrete          #+#    #+#             */
/*   Updated: 2022/11/13 17:25:26 by pcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*--------------------------------------------------------------------------------------------
*	number_check.c
*
*	number_check.c se usa para comprobar si el número que ponemos/vamos a poner en la matriz 
*	es válido o no. Hay dos comprobaciones:
*		1. Si el número está repetido en alguna fila o columna (no puede repetirse)
*		2. Si el número cumple con las condiciones impuestas por los número externos
*	
*	- check_conditions(): comprueba si la columna (col) o fila (row) que recibe están completas.
*	Si lo están comprueba si están cumpliendo las condiciones impuestas por los número externos.
*		1. Obtiene tamaño de matriz llamando a la funcion get_size(box)
*		2. Si la fila es la última quiere decir que estamos completando una columna:
*			a b c d
*			-------		
*			1 x x x		'4' muestra el número que estaríamos colocando si la fila es la última.
*			2 x x x		Por lo tanto hemos completado la columna "1 2 3 4" y necesitamos comprobar
*			3 x x x		con las condiciones (a, e).
*			4      
*			-------
*			e f g h
*
*			Para obtener la columna, declaramos un array (column_array), y sacamos el array de la matriz
*			con la función get_column().
*		3. La función ft_is_possible() devuelve 1 si el número se puede colocar y 0 si no.
*		   Así si nos devuelve 0 (fallo) devolvemos 0 (fallo) y el programa no colocará el número
*		   que se ubica en la intersección de col y row.
*		4. Especial atención al uso de free() para liberar el espacio que habíamos reservado al crear
*		   el array column_array
*		5. Se repite el proceso entre los pasos 2.-4. Con la salvedad de que el array de la fila lo
*		   conseguimos con hacer box[row].
*	
*	- correct_position(): itera primero por columna y luego por fila para comprobar que el número
*		pasado como parámetro (num) no esté repetido en la columna (col) y fila (row) pasadas por parámetro
*		Cuando es necesario el tamaño usamos la función get_size(box). 
*	
*	- ft_is_possible(): comprueba que las condiciones de contorno que se pasan como argumentos
*		se cumplan para un array que también se pasa por array. Para comprobar cada una de las 
*		condiciones se llama a las funciones ft_number_x y ft_number_y.
*
*	- ft_number_x() y ft_number_y(): comprueban que un array concreto cumpla la condición x (recorre el array
*		desde el 0 hasta el último) o la condición y (recorre es array desde el último al 0).
-----------------------------------------------------------------------------------------------*/

#include <unistd.h>
#include <stdlib.h>

int		get_size(char **box);
char	*get_column(char **box, int size, int col);

int	ft_number_y(char *tab, char y, int size)
{	
	int		i;
	char	max;
	char	c;

	i = size - 1;
	c = '1';
	max = tab [size - 1];
	while (i >= 0)
	{
		if (max < tab[i - 1])
		{
			max = tab[i - 1];
			c++;
		}
		i--;
	}
	if (y == c)
		return (1);
	return (0);
}

int	ft_number_x(char *tab, char x, int size)
{
	int		i;
	char	max;
	char	c;

	i = 0;
	c = '1';
	max = tab [i];
	while (i <= size - 1)
	{
		if (max < tab[i + 1])
		{
			max = tab[i + 1];
			c++;
		}
		i++;
	}
	if (x == c)
		return (1);
	return (0);
}

int	ft_is_possible(char *tab, char x, char y, int size)
{
	int	number_x;
	int	number_y;

	number_x = ft_number_x(tab, x, size);
	number_y = ft_number_y(tab, y, size);
	if (number_x == 1 && number_y == 1)
		return (1);
	else
		return (0);
}

int	correct_position(char **box, int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < get_size(box))
	{
		if (box[row][i] == '0' + num)
			return (0);
		i++;
	}
	i = 0;
	while (i < get_size(box))
	{
		if (box[i][col] == '0' + num)
			return (0);
		i++;
	}
	return (1);
}

int	check_conditions(char **box, char **cond, int row, int col)
{
	char	*column_array;
	int		size;

	size = get_size(box);
	if (row == size - 1)
	{
		column_array = get_column(box, size, col);
		if (ft_is_possible(column_array, cond[0][col], cond[1][col], size) == 0)
		{
			free (column_array);
			return (0);
		}
		free (column_array);
	}
	if (col == size -1)
	{
		if (ft_is_possible(box[row], cond[2][row], cond[3][row], size) == 0)
			return (0);
	}
	return (1);
}
