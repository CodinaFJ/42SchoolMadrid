/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarrete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:22:30 by pcarrete          #+#    #+#             */
/*   Updated: 2022/11/13 17:27:02 by pcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*--------------------------------------------------------------------------------------------
	solver.c 

	El "corazón" del programa. Aquí está el argoritmo que soluciona el cuadrado.

	- main(): función desde la que se inicia la resolución del ejercicio. Aquí empieza y acaba todo.
		1.	Con sanity_check() comprobamos que el enunciado que se nos da es correcto. Si no sacamos
			"Error" por pantalla y se acaba el programa.
		2.	Con initialize_conditions() creamos el array de arrays conditions y lo llenamos con
			los valores pasados como argumento al ejecutar el programa.
		3.	Con initialize_box() creamos la matriz en la que meteremos los números de la solución.
			Aquí sólo creamos una matriz de tamaño acorde al enunciado y la llenamos de '0'.
		4.	Al llamar a solve() intentamos solucionar el problema. Si se encuentra alguna solución
			la sacamos por pantalla con print_box(). Si no, sacamos por pantalla "Error".
	
	- solve(): es una función recursiva que se va a llamar una vez por cada número a rellenar
		en el cuadrado. Prueba en cada posición qué número cumple las reglas (no repetición y marco).
		Si encuentra un número posible en todos los huecos, entonces devuelve 1 y sabemos que el
		cuadrado ha sido rellenado correctamente. Si no, devuelve 0 y sabemos que no hay solución.
		
		1.	Comprobamos si estamos en final de fila (col_ended()), si es la última fila
			devolvemos 1 diciendo que ya no hay nada más que rellenar. Si no es la última reiniciamos
			col y pasamos a la siguiente fila.
		2.	Entramos en el bucle que va probando números del 1-size para ver cual puede ir en la
			intersección col-row. Si encontramos uno que no se repita en col-row y cumpla condiciones
			externas, llamamos a recursión pero en el siguiente número de la fila actual (col + 1).
		3.	Si el resultado de la recursión es 1 quiere decir que todos los números que hay por delante
			han sido colocados correctamente. Por lo que el que hemos colocado aquí también lo es, asi
			que devolvemos 1 también. Si el resultado de la recursión no fuera 1 probaríamos con el
			siguiente número del bucle (número + 1).
		4.	Si el bucle llega al final sin colocar número exitosamente el cuadrado es irresoluble y
			la función devuelve 0.
		
	- col_ended(): comprueba si la intersección entre row y col está al final de una fila.
		Si lo está y es la última fila devuelve 1 indicando que hemos terminado.
		Si lo está y no es la última fila pone col = 0 y pasa a la siguiente linea. (Movimiento de 
		máquina de escribir).

	- initilize_box(): reserva suficiente espacio para la matriz dónde colocaremos la solución al
	ejercicio y la llena de 0. 
		1.	Reservamos espacio para un array de (char*)
		2.	Reservamos espacio por cada elemento del array del paso 1. Reservamos para datos tipo (char)
		3.	Llenamos de 0.

		box
		 |	 _______
		[0]	|0 0 0 0|
		[1]	|0 0 0 0| -> Cada uno de los elementos de los array en la "box" es un (char)
		[2]	|0 0 0 0|
		[3]	|0 0 0 0|
		 |	 -------
	Cada uno de
	los elementos 
	de este array
	box es (char*)	 
-----------------------------------------------------------------------------------------------*/

#include <unistd.h>
#include <stdlib.h>

int		sanity_check(int argc, char **argv, int *size);
int		correct_position(char **box, int row, int col, int num);
int		check_conditions(char **box, char **conditions, int row, int col);
int		get_size(char **box);
void	print_box(char **box);
void	fill_conditions(char **conditions, int size, char **argv);
char	**initialize_conditions(char **conditions, char **argv, int size);

char	**initialize_box(char **box, int size)
{
	int	i;
	int	j;

	box = malloc((size + 1) * sizeof (char *));
	i = 0;
	j = 0;
	while (i < size)
	{
		box[i] = malloc((size + 1) * sizeof (char));
		while (j < size)
		{
			box[i][j] = '0';
			j++;
		}
		box[i][j] = 0;
		i++;
		j = 0;
	}
	box[i] = 0;
	return (box);
}

int	col_ended(int *row, int *col, int size)
{
	if (*row == size - 1 && *col == size)
		return (1);
	if (*col == size)
	{
		*row = *row + 1;
		*col = 0;
	}
	return (0);
}

int	solve(char **box, int row, int col, char **conditions)
{
	int	i;
	int	size;

	i = 0;
	size = get_size(box);
	if (col_ended(&row, &col, size) == 1)
		return (1);
	while (i <= size)
	{
		if (correct_position (box, row, col, i) == 1)
		{
			box[row][col] = '0' + i;
			if (check_conditions(box, conditions, row, col) == 1)
			{
				if (solve (box, row, col + 1, conditions) == 1)
					return (1);
			}
		}
		box[row][col] = '0';
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	**box;
	char	**conditions;
	int		size;

	(void) argc;
	(void) argv;
	conditions = NULL;
	box = NULL;
	if (sanity_check(argc, argv, &size) != 1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	conditions = initialize_conditions(conditions, argv, size);
	box = initialize_box(box, size);
	if (solve (box, 0, 0, conditions) == 1)
		print_box(box);
	else
		write(1, "Error\n", 6);
	return (0);
}
