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
# define DICT_ERROR "Dict Error\n"
# define ERROR "Error\n"

void			ft_putchar(char c);
void			ft_swap(int *a, int *b);
void			ft_putstr(char *str, int fd);
int				ft_strlen(char *str);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strcat(char *dest, char *src);
int				ft_strstr(char *str, char *to_find);
unsigned long	*ft_sort_int_tab(unsigned long *tab, unsigned long size);
int				ft_str_is_numeric(char *str);

#endif