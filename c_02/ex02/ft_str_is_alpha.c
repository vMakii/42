/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:02:28 by mivogel           #+#    #+#             */
/*   Updated: 2024/07/01 15:17:18 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'a' && str[i] <= 'z'))
		{
			if (!(str[i] >= 'A' && str[i] <= 'Z'))
			{
				return (0);
			}
		}
		i++;
	}
	return (1);
}
/*
#include <stdio.h>

int main(){
	char* c = "";
	int n = ft_str_is_alpha(c);
	printf("%d", n);
}*/
