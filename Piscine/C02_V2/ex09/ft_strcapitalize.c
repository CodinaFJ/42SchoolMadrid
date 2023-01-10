/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:37:46 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/08 18:37:07 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_isalphanum(char c)
{
	int		n;

	n = 0;
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'))
		n = 1;
	return (n);
}

char	*ft_strlowcase(char *str)
{
	int		i;

	i = 0;
	while (*(str + i) != 0)
	{
		if (*(str + i) > 64 && *(str + i) < 91)
			*(str + i) += 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		alpha;

	i = 0;
	alpha = 0;
	ft_strlowcase(str);
	while (str[i] != 0)
	{
		if (ft_isalphanum(str[i]) == 1 && alpha == 0)
		{
			alpha = 1;
			if (str[i]> 96 && str[i] < 123)
				str[i] = str[i] - 32;
		}
		else if (ft_isalphanum(str[i]) == 0)
			alpha = 0;
		i++;
	}
	return (str);
}

/*int	main(void)
{	
	char	str[] = "TtHnI/34^]K*{";

	ft_strcapitalize(str);
	write(1, str, sizeof(str));
	write(1, "\n", 1);
	return (0);
}*/
