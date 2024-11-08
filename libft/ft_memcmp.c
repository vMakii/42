/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:19:50 by mivogel           #+#    #+#             */
/*   Updated: 2024/11/07 14:43:55 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && *(unsigned char *)(ptr1 + i) == *(unsigned char *)(ptr2
			+ i))
		i++;
	if (i < n)
		return (*(unsigned char *)(ptr1 + i) - *(unsigned char *)(ptr2 + i));
	return (0);
}
