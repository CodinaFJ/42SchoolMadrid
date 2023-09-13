/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:15:00 by jcodina-          #+#    #+#             */
/*   Updated: 2023/03/17 17:48:40 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

/**
 * Locates first occurrence of c in string s.
 * @param s searched string.
 * @param c character to search.
 * @return Pointer to byte located, or NULL if there is no occurrence.
 */
char	*ft_strchr(char *s, int c)
{
	size_t	i;
	size_t	n;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	n = i;
	i = 0;
	while (i < n)
	{
		if ((*(s + i)) == (unsigned char)c)
			return (s + i);
		i++;
	}
	return (NULL);
}

size_t	txt_line_size(char *str, size_t *line_len)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		i++;
		if (*line_len == 0 && str[i] == '\n')
			*line_len = i + 1;
	}
	if (*line_len == 0)
		*line_len = i;
	if (str[0] == '\n')
		*line_len = 1;
	return (i);
}

int	fill_txt(char **txt, char **buffer_read, int *read_len, int fd)
{
	while (!ft_strchr(*txt, (int) '\n'))
	{
		*buffer_read = (char *) ft_calloc((BUFFER_SIZE + 1) * sizeof(char), 1);
		if (!(*buffer_read))
			return (-1);
		*read_len = read(fd, *buffer_read, BUFFER_SIZE);
		if (*read_len == -1)
		{
			free(*buffer_read);
			free(*txt);
			txt = NULL;
			buffer_read = NULL;
			return (-1);
		}
		else if (*read_len == 0)
			break ;
		*txt = ft_strjoin_free(txt, buffer_read);
		if (!(*txt))
			return (-1);
	}
	return (0);
}

char	*extract_line(char **txt, char **buffer_read)
{
	size_t	line_len;
	size_t	txt_len;
	char	*line;
	char	*new_txt;

	if (*buffer_read != NULL)
	{
		free(*buffer_read);
		buffer_read = NULL;
	}
	line_len = 0;
	txt_len = txt_line_size(*txt, &line_len);
	if (txt_len == 0)
		return (NULL);
	line = ft_substr(*txt, 0, line_len);
	new_txt = ft_substr(*txt, line_len, txt_len - line_len);
	free(*txt);
	*txt = NULL;
	*txt = new_txt;
	if (*txt && **txt == '\0')
	{
		free(*txt);
		*txt = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*txt[OPEN_MAX];
	char		*buffer_read;
	int			read_len;

	read_len = -1;
	buffer_read = NULL;
	if ((int) fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{	
		if (txt[fd])
		{
			free(txt[fd]);
			txt[fd] = NULL;
		}
		return (NULL);
	}
	if (fill_txt(&txt[fd], &buffer_read, &read_len, fd) == -1)
		return (NULL);
	return (extract_line(&txt[fd], &buffer_read));
}
