/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_mgmt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:53:40 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/20 18:53:43 by jcodina-         ###   ########.fr       */
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

unsigned long	ul_atoi(char *str)
{
	unsigned long	i;
	unsigned long	num;

	num = 0;
	i = 0;
	if (ft_strlen(str) == 0)
		return (NULL);
	while (*(str + i) >= '0' && *(str + i) <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num);
}

int	check_end_of_number(int nbr, t_entry_str *dict, int fd)//fd es un residuo de unas pruebas
{
	if (nbr == 0)
		return (1);
	else if (nbr <= 20)
	{
		ft_putstr(get_str_from_num(nbr, dict), fd);//Si es menor que 20, buscamos en la lista del tirón. Y escribimos
		return (1);
	}
	else if (nbr < 100)//Si es menor que 100, gestionamos dividiendo en decenas y unidades
	{
		ft_putstr(get_str_from_num((nbr / 10) * 10, dict), fd);//Miramos la decena y buscamos en diccionario. Y escribimos
		if ((nbr % 10) != 0)
			ft_putstr(get_str_from_num(nbr % 10, dict), fd);//Miramos la unidad y buscamos en diccionario. Y escribimos
		return (1);
	}
	return (0);
}

//Función recursiva que divide las llamadas a busqueda de str por cada numero
void	nbr_to_str(unsigned long nbr, t_entry_str *dict,
	unsigned long *nums_to_div, int i)
{
	unsigned long	n;

	//Terminamos la recursividad mirando si el numero es menor que 100
	if (check_end_of_number(nbr, dict, 1) == 1)
		return ;
	n = nbr / nums_to_div[i];
	if (n != 0)
	{
		nbr_to_str(n, dict, nums_to_div, 0);//Gestionamos el numero "cabeza" de los que hemos dividido RECURSION
		ft_putstr(get_str_from_num(nums_to_div[i], dict), 1);//Immprimimos el divisor (million, thousand, hundred...)
		nbr_to_str(nbr % nums_to_div[i], dict, nums_to_div, i + 1);//Gestionamos lo que nos quede dividiendo por el siguiente numero RECURSION
	}
	else if (n == 0)
		nbr_to_str(nbr, dict, nums_to_div, i + 1);//RECURSION -> no ha valido el numero que hemos probado a dividir, usamos el next mas peque
}

unsigned long	*nums_to_divide(t_entry_str *dict, int rows)
{
	unsigned long	*nbrs_div;
	int				i;

	i = 0;
	nbrs_div = malloc((rows) * sizeof(int));
	while (dict != NULL)
	{
		nbrs_div[rows - 1 - i] = dict->nbr;
		dict = dict->next;
		i++;
	}
	ft_sort_int_tab(nbrs_div, rows + 1);
	return (nbrs_div);
}
