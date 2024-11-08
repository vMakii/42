/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:18:43 by mivogel           #+#    #+#             */
/*   Updated: 2024/11/05 17:58:04 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_display_file(int fd)
{
	char	buffer;

	while (read(fd, &buffer, 1) != 0)
		ft_putchar(buffer);
}

int	main(int ac, char **av)
{
	int	fd;

	if (ac != 2)
	{
		if (ac > 2)
			ft_putstr("Too many arguments.\n");
		if (ac < 2)
			ft_putstr("File name missing.\n");
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Cannot read file.\n");
		return (1);
	}
	ft_display_file(fd);
	close(fd);
	return (0);
}
