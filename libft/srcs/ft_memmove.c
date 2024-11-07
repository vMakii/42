/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:51:08 by mivogel           #+#    #+#             */
/*   Updated: 2024/11/07 17:02:46 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*cdst;
	const unsigned char	*csrc;

	if (!dst && !src)
		return (NULL);
	if (dst < src)
	{
		cdst = dst;
		csrc = src;
		while (n--)
			cdst[n] = csrc[n];
	}
	else
	{
		ft_memcpy(dst, src, n);
	}
	return (dst);
}
