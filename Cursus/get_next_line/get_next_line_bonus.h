/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:27:04 by jcodina-          #+#    #+#             */
/*   Updated: 2023/03/17 17:51:58 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(char *str);
char	*ft_strjoin_free(char **s1, char **s2);
void	*ft_calloc(size_t count, size_t size);

#endif