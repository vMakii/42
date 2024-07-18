/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:40:14 by mivogel           #+#    #+#             */
/*   Updated: 2024/07/18 11:20:14 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}
/*
#include <stdio.h>

int main()
{
	char *c1 = "geoffrey";
	//char *c2 = "abcd";
	char *c3 = "burtin";
	int n;
	printf("%d", n = ft_strcmp(c1, c3));
}*/
