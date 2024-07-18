/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:39:25 by mivogel           #+#    #+#             */
/*   Updated: 2024/07/02 09:11:28 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 1;
	ft_strlowcase(str);
	if (str[i -1] >= 'a' && str[i - 1] <= 'z')
		str[i - 1] -= 32;
	while (str[i])
	{
		if (!((str[i - 1] >= 'a' && str[i - 1] <= 'z') \
				|| (str[i - 1] >= 'A' && str[i - 1] <= 'Z' ) \
				|| (str[i - 1] >= '0' && str[i - 1] <= '9')))
		{
			if ((str[i] >= 'a' && str[i] <= 'z'))
				str[i] -= 32;
		}
		i++;
	}
	return (str);
}
/*
#include <stdio.h>

int main(){
	char c[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	ft_strcapitalize(c);
	printf("%s", c);
}*/
