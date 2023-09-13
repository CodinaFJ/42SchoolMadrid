/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:33:57 by jcodina-          #+#    #+#             */
/*   Updated: 2023/04/09 17:03:26 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	main(int argc, char **argv)
{
	int size;
	int *p, *q;
	int d;
	
	d = 42;
	p = NULL;
	(void) argc;
	(void) argv;
	size = ft_printf("%p", p);
	printf("\n%d\n", size);
	printf("\n%d\n",printf("%p", p));
	printf("Putnbr pointer: ");
	return (0);
}