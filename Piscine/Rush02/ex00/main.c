/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:23:02 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/19 19:23:05 by jcodina-         ###   ########.fr       */
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

//Control de errores: pasamos argumentos y un string para coger todo el texto
//	1. Miramos si hay 1 solo argumento (argc == 2): usamos el dicionario estandar
//	2. Miramos si hay 2 argumentos: usamos dict dado
//	3. Otro caso da error
int	args_num_check(int argc, char **argv, char **file_text)
{
	if (argc == 2)
	{
		//En read_file leemos todo el diccionario estandar (no nos han dado otro)
		if (read_file("numbers.dict",
				calc_buffer("numbers.dict"), file_text) == -1)
			return (-1);//Por si hay fallo
		//Comprobar que el argumento que nos dan es numérico
		if (ft_str_is_numeric(argv[1]) == -1)
		{
			ft_putstr(ERROR, 1);
			return (-1);//Por si hay fallo
		}
	}
	//Nos han debido de dar un dict nuevo. Leemos ese
	else if (argc == 3)
	{
		//Leemos el dict nuevo que tiene que estar en argv[1]
		if (read_file(argv[1], calc_buffer(argv[1]), file_text) == -1)
		{
			ft_putstr(DICT_ERROR, 1);
			return (-1);//Por si falla
		}
	}
	//Si nos dan algo distinto a 1 o 2 argumentos -> ERROR
	else
	{
		ft_putstr(ERROR, 1);
		return (-1);
	}
	return (1);//Si va todo bien devolvemos 1
}

//Paso intermedio hasta llegar a la función resolvedora (nbr_to_str)
int	solve_number(char *argv1, t_entry_str *dict, unsigned long	*nums_to_div)
{
	if (ul_atoi(argv1) == 0)//Si es el cero, lo ponemos a pincho
	{
		ft_putstr(get_str_from_num(0, dict), 1);//Buscamos el 0 en la lista e imprimimos el string 
		return (0);
	}
	nbr_to_str(ul_atoi(argv1), dict, nums_to_div, 0);//Llamamos a la función recursiva reina
	return (0);
}

void	frees(char *file_text, unsigned long *nums_to_div,
				t_entry_str *dict, char **text_rows)
{
	free(file_text);
	free(nums_to_div);
	//Funciones para loopear por las matrices y liberar array a array
	free_lst(dict);
	free_text_rows(text_rows);
}

//Funcion principal desde donde arranca el programa
int	main(int argc, char **argv)
{
	char			*file_text;//Array con toooooodo el texto todo seguido del dict
	char			**text_rows;//Todo el texto divido en un string por fila
	unsigned long	*nums_to_div;//Numeros a usar cuando hagamos divisiones durante la recursión
	t_entry_str		*dict;//Puntero a la primera entrada de la lista
	int				error;//Variable para propagar el error

	//Checkeo de errores en las entradas de argumento
	if (args_num_check(argc, argv, &file_text) == -1)
		return (1);
	//Aqui divimos el troncho de texto de file_text en un string por fila del archivo. le pasamos el troncho y en cuantas filas tiene que dividir
	text_rows = divide_file_text(file_text, calc_rows(file_text));
	//A cada fila le eliminamos el salto de linea (y sustitouimos por espacio)
	text_rows = rmv_cr(text_rows);
	//Rellenamos el diccionario (lista enlazada) que es lo que usamos en el solver
	dict = fill_dict(text_rows, 0, malloc(sizeof(t_entry_str)), &error);
	if (error == -1)//Por si hubiera habido error durante la creación del dict
	{
		ft_putstr(DICT_ERROR, 1);
		return (2);
	}
	nums_to_div = nums_to_divide(dict, calc_rows(file_text));
	//Solve_number procesa el número y descubre en qué orden hay que descomponerlo para poner los nombres
	//Le paso el ultimo argumento, el diccionario (lista enlazada), numeros ordenados decrecientemente
	if (solve_number(argv[argc - 1], dict, nums_to_div) == -1)
	{
		ft_putstr(DICT_ERROR, 1);
		return (3);
	}
	write(1, "\n", 1);
	frees(file_text, nums_to_div, dict, text_rows);//Liberamos toda la memoria que tenemos bloqueada
	return (0);
}
