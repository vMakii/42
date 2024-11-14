/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:01:46 by mivogel           #+#    #+#             */
/*   Updated: 2024/11/12 12:07:32 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != (char)c)
		i++;
	if (str[i] == (char)c)
		return ((char *)str + i);
	return (NULL);
}
// char	*ft_strchr(const char *str, int c)
// {
// 	size_t	i;
//
// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == (char)c)
// 			return ((char *)str + i);
// 		i++;
// 	}
// 	if (c == 0)
// 		return ((char *)str + i);
// 	return (NULL);
// }
