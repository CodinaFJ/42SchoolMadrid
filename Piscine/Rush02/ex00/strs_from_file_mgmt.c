/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_from_file_mgmt.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:03:33 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/20 19:03:34 by jcodina-         ###   ########.fr       */
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

char	**rmv_cr(char	**text_rows)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (text_rows[i])
	{
		while (text_rows[i][j])
		{
			if (text_rows[i][j] == '\n')
				text_rows[i][j] = ' ';
			j++;
		}
		i++;
		j = 0;
	}
	return (text_rows);
}

char	*fill_row_to_str(char *str, int i, int j)
{
	char	*dest;

	dest = malloc(j * sizeof(char));//Reserva tamaño para el string (tamaño que hemo calculado antes)
	j = 0;
	while (str[i] != '\0')
	{
		dest[j] = str[i];//copiamos string 
		i++;
		j++;
	}
	dest[i] = 0;
	return (dest);//devolvemos string
}

char	*row_to_str(char *str, int *error)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != ':')//Avanza hasta el caracter ':'
		i++;
	i++;
	while (str[i] == ' ' || str[i] < 32)//Avanza todos los caracteres no imprimibles
	{
		if (str[i] == '\0')//Si encuentra un nulo antes de encontrar algo imprimible, fallo (está vacío)
		{
			*error = -1;
			return (NULL);
		}
		i++;
	}//El bucle termina al encontrar un caracter imprimible, guardamos esa posicion en i
	j = i;
	while (str[j] != '\0')
		j++;//Calculamos la longitud del string que queremos guardar
	return (fill_row_to_str(str, i, j));//Retornamos el string
}

//Calcula número de filas de dict
int	calc_rows(char *file_text)
{
	int	rows;

	rows = 0;
	while (*file_text)
	{
		//Cada vez que encontramos salto de linea, aumentamos numero de lineas

		if (*file_text == '\n')
			rows++;
		file_text++;
	}
	return (rows);
}

//Un buclle infernal. 
char	**divide_file_text(char *file_text, int rows)
{
	char	**text_rows;//Aqui vamos a guardar  las filas divididas en strings
	int		*size_rows;	//El tamaño de cada fila-> cuantos caracteres hay en cada linea
	int		i;
	int		j;

	i = 0;
	j = 0;
	text_rows = malloc((rows + 1) * sizeof(char *));
	text_rows[rows] = NULL;
	size_rows = calc_size_rows(file_text, rows);
	while (i < rows)
	{
		text_rows[i] = malloc((size_rows[i] + 1) * sizeof(char));
		*(text_rows[i] + size_rows[i]) = '\0';
		while (j < size_rows[i])
		{
			text_rows[i][j] = *file_text++;
			j++;
		}
		text_rows[i][size_rows[i]] = '\0';
		i++;
		j = 0;
	}
	free(size_rows);
	return (text_rows);
}
