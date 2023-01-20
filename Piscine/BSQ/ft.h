/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:58:40 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/17 16:58:43 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_H
# define FT_H
# ifdef linux
# include <unistd.h>
# endif
# ifdef _WIN32
# include <io.h>
# endif

void	ft_putstr(char *str);
int		ft_strlen(char *str);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
void	ft_putnbr(int nb);
int		ft_atoi_n(char *str, int n);
char	*ft_rmv_cr(char *str);
char	*ft_strncat(char *dest, char *src, unsigned int nb);
void	ft_putnbr_blnk(int nb);
int		check_min(int a, int b, int c);
int		ft_char_printable(char c);

#endif