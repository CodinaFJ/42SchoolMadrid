/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:55:53 by jcodina-          #+#    #+#             */
/*   Updated: 2023/04/09 17:16:57 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_variable(char vars_id, va_list ptr)
{
	int	size;

	size = 0;
	if (vars_id == 'c')
		size = printf_char(va_arg(ptr, int));
	else if (vars_id == 's')
		size = printf_str(va_arg(ptr, char *));
	else if (vars_id == 'u')
		size = printf_unbr(va_arg(ptr, unsigned int));
	else if (vars_id == 'i' || vars_id == 'd')
		size = printf_nbr(va_arg(ptr, int));
	else if (vars_id == 'p')
		size = printf_ptr(va_arg(ptr, long long));
	else if (vars_id == 'x')
		size = printf_hex_low(va_arg(ptr, int));
	else if (vars_id == 'X')
		size = printf_hex_upp(va_arg(ptr, int));
	else if (vars_id == '%')
		size = write(1, "%", 1);
	else
		ft_putstr_fd("\nERROR VAR\n", 0);
	return (size);
}

int	ft_putstr_limper(const char *str, int i, int *size)
{
	int	j;

	j = 0;
	while (str[i + j] && str[i + j] != '%')
		j++;
	write(1, &str[i], j);
	*size += j;
	return (i + j);
}

int	ft_printf(const char *input, ...)
{
	va_list	ptr;
	int		i;
	int		size;

	i = 0;
	size = 0;
	va_start(ptr, input);
	while (input[i])
	{
		i = ft_putstr_limper(input, i, &size);
		if (!input[i])
			break ;
		i++;
		size += print_variable(input[i], ptr);
		i++;
	}
	va_end(ptr);
	return (size);
}
