/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:53:14 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/24 15:53:16 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

int	in_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (*(charset + i) != 0)
	{
		if (*(charset + i) == c)
			return (1);
		i++;
	}
	return (0);
}

int	get_size_strs(char *str, char *charset)
{
	int	i;
	int	size;

	i = 0;
	size = 1;
	while (str[i] != 0 && *charset != 0)
	{
		if (in_charset(str[i], charset) == 1)
		{
			size++;
			while (in_charset(str[i], charset) == 1)
				i++;
		}
		else
			i++;
	}
	return (size);
}

int	word_len(char *str, char *charset)
{
	int	i;

	i = 0;
	while (in_charset(str[i], charset) == 0 && str[i])
		i++;
	return (i);
}

char	*get_split_word(char **str, char *charset)
{
	int		k;
	int		wrd_len;
	char	*res;

	k = 0;
	wrd_len = word_len(*str, charset);
	res = malloc((wrd_len + 1) * sizeof(char));
	while (k < wrd_len)
	{
		res[k] = **str;
		*str = *str + 1;
		k++;
		if (**str == 0)
			break ;
	}
	res[k] = 0;
	return (res);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		j;
	int		k;
	int		wrd_len;

	wrd_len = 0;
	j = 0;
	k = 0;
	strs = (char **)malloc((get_size_strs(str, charset) + 1) * sizeof(char *));
	strs[get_size_strs(str, charset) + 1] = 0;
	while (*str != 0)
	{
		if (in_charset(*str, charset) == 0)
		{
			strs[j] = get_split_word(&str, charset);
			j++;
		}
		while (in_charset(*str, charset) == 1)
			str++;
	}
	return (strs);
}

// void	ft_putstr(char *str)
// {
// 	int		i;

// 	i = 0;
// 	while (*(str + i) != 0)
// 		i++;
// 	write(1, str, i);
// }

// int	main(int argc, char **argv)
// {
// 	(void) argc;
// 	(void) argv;
// 	int i;
// 	char **strs;

// 	strs = ft_split(argv[1], argv[2]);
// 	i = 0;
// 	while(*strs != NULL)
// 	{
// 		ft_putstr(*strs);
// 		ft_putstr("\n");
// 		strs++;
// 	}
// 	return (0);
// }