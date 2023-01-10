/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:50:50 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/20 18:50:53 by jcodina-         ###   ########.fr       */
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

//Funcion recursiva para rellenar una lista enlazada
//Como la lista se construye en una función y se devuelve por referencia. Hay que reservar memoria con malloc
t_entry_str	*fill_dict(char **text_rows, int row, t_entry_str *new_entry,
							int *error)
{
	if (text_rows[row] == NULL)//Cuando ya no hay mas filas, cerramos recursion devolviendo NULL (la última entrada de la lista apunta a NULL)
	{
		free(new_entry);//Liberamos el espacio que estábamos creando para esta estructura que finalmente no queremos
		return (NULL);
	}
	new_entry->nbr = ul_atoi(text_rows[row]);//De toda la fila sacamos el numero
	new_entry->str = row_to_str(text_rows[row], error);//De toda la fila sacamos el string
	if (*error == -1)
		return (NULL);//Error
	new_entry->next = fill_dict//Apunta a la siguiente cajita (entrada de la lista) que vamos a crear en la recursión
		(text_rows, row + 1, malloc(sizeof(t_entry_str)), error);
	return (new_entry);
}

//busca por toda la lista enlazada y devuelve el string asociado al numero dado
char	*get_str_from_num(unsigned long nbr, t_entry_str *dict)
{
	if (dict->nbr == nbr)
		return (dict->str);
	else if (dict->next == NULL)
		return ("Dict Error");
	return (get_str_from_num(nbr, dict->next));
}
