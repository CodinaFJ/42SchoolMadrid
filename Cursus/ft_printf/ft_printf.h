/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:55:46 by jcodina-          #+#    #+#             */
/*   Updated: 2023/04/09 17:18:02 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include "libft/libft.h"

int	ft_printf(const char *format, ...);
int	printf_char(char var);
int	printf_str(char *var);
int	printf_nbr(int var);
int	printf_unbr(unsigned int var);
int	printf_ptr(long long var);
int	printf_hex_low(long long var);
int	printf_hex_upp(long long var);

#endif