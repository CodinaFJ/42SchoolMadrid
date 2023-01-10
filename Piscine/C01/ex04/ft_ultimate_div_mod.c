/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:06:01 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/07 14:06:04 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int		a_aux;
	int		b_aux;

	a_aux = *a;
	b_aux = *b;
	*a = a_aux / b_aux;
	*b = a_aux % b_aux;
}
