/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmunoz <tmunoz@student.42madrid.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:15:10 by tmunoz            #+#    #+#             */
/*   Updated: 2022/11/05 14:16:48 by tmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_putchar(char pixel);

int	rush(const int width, const int height)
{
    /* La función no puede trabajar correctamente sino cumple el valor minimo de 1,1*/
	int		min_size;
	int		current_line;
	int		current_column;

	min_size = 1;
	current_line = 1;
	current_column = 1;
	if (width < min_size || height < min_size)
	{
		return (0); /*terminamos el programa porque no hay valores validos para crear el rectángulo*/
	}
    /* como escribimos por lineas empezamos siempre por el ancho*/
	while (current_line <= height)
	{
        /*y ahora vamos añadiendo uno a uno los "pixeles" variando su valor dependiendo de la posición actual*/
		while (current_column <= width)
		{
            /*Comprobamos si es esquina*/
			if (( current_line == 1 || current_line == height) && (current_column == 1 || current_column == width))
			{
				ft_putchar('o');
			}
            /*Comprobamos si es lado superior o inferior*/
            else if ( current_line == 1 || current_line == height)
			{
                ft_putchar('-');
            }
            /*Comprobamos si lado izquierdo o derecho*/
            else if(current_column == 1 || current_column == width)
			{
                ft_putchar('|');
            }
            /*Ya solo nos queda el interior*/
            else 
			{
                ft_putchar(' ');    
            }
            ++current_column;
        }
        /*terminamos la lina y acualizamos su valor*/
        ft_putchar('\n');
        ++current_line;
        /*inicializamos la columna a la primera posicion*/
        current_column = 1;
    }
    /* FIN*/
    return(0);
}
