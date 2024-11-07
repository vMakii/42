/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:50:08 by mivogel           #+#    #+#             */
/*   Updated: 2024/11/07 11:56:55 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memchr(const void *block, int c, size_t n)
{
	size_t	i;

	if (!block)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(block + i) == (unsigned char)c)
			return ((void *)(block + i));
		i++;
	}
	return (NULL);
}
