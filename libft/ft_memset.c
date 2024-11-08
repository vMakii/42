/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:26:08 by mivogel           #+#    #+#             */
/*   Updated: 2024/11/08 09:12:04 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *)ptr;
	if (!str)
		return (NULL);
	i = 0;
	while (i < n)
	{
		str[i] = value;
		i++;
	}
	return (ptr);
}
