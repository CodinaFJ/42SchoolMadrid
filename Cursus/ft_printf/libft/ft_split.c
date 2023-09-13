/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:22:16 by jcodina-          #+#    #+#             */
/*   Updated: 2023/02/08 09:54:24 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
/**
 * Used to protect double pointer array p form allocation error.
 * Liberates n arrays in p and p.
 * @param p Double pointer to liberate recursively.
 * @param n Number of arrays in p to free. 
 * @return NULL
 */
void static	*ft_free_darray(void **p, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(p[i]);
		i++;
	}
	free(p);
	return (NULL);
}

static	int	ft_get_size_strs(char const *str, char c)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i] != 0 && c != '\0')
	{
		if (str[i] != c)
		{
			size++;
			while (str[i] != c && str[i] != '\0')
				i++;
		}
		else
			i++;
	}
	if (c == 0 || (size == 0 && !ft_strchr(str, c)))
		return (1);
	else if (size == 0)
		return (0);
	return (size);
}

static	char	**ft_split_loop(char **strs, char const *str, char c,
	size_t str_len)
{
	size_t	i;
	int		j;
	int		wrd_len;

	i = 0;
	j = 0;
	while (i < str_len)
	{
		if (str[i] != c)
		{
			wrd_len = 0;
			while (str[i + wrd_len] != c && str[i + wrd_len])
				wrd_len++;
			strs[j] = ft_substr(str, i, wrd_len);
			if (strs[j] == NULL)
				return (ft_free_darray((void **)strs, j + 1));
			j++;
			while (str[i] != c && str[i] != '\0')
				i++;
		}
		while (str[i] == c && str[i] != '\0')
			i++;
	}
	return (strs);
}

/**
* Fills an array of strings with the results of dividing the string str
* using the char c as separator. Array returned is null terminated.
* @param str string to divide
* @param c separator char
* @return null terminated array of strings
*/
char	**ft_split(char const *str, char c)
{
	char	**strs;
	int		strs_size;

	if (*str == '\0')
	{
		strs = malloc(sizeof(char *));
		if (!strs)
			return (NULL);
		strs[0] = NULL;
		return (strs);
	}
	strs_size = ft_get_size_strs(str, c);
	strs = (char **)malloc((strs_size + 1) * sizeof(char *));
	if (!strs)
		return (ft_free_darray((void **)strs, 0));
	strs[strs_size] = NULL;
	strs = ft_split_loop(strs, str, c, ft_strlen(str));
	return (strs);
}
