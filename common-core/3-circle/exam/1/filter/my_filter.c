/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_filter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 11:22:28 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/17 11:27:22 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void	replace_occurrences(char *buffer, int size, char *target,
		int target_len)
{
	char	*found;
	int		i;

	while ((found = memmem(buffer, size, target, target_len)) != NULL)
	{
		i = 0;
		while (i < target_len)
		{
			found[i] = '*';
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	char	*buffer;
	char	*target;
	int		target_len;
	int		bytes_read;

	if (argc != 2 || !argv[1] || strlen(argv[1]) == 0)
		return (1);
	target = argv[1];
	target_len = strlen(target);
	buffer = malloc(BUFFER_SIZE);
	if (!buffer)
	{
		perror("Error");
		return (1);
	}
	while ((bytes_read = read(0, buffer, BUFFER_SIZE)) > 0)
	{
		replace_occurrences(buffer, bytes_read, target, target_len);
		if (write(1, buffer, bytes_read) == -1)
		{
			perror("Error");
			free(buffer);
			return (1);
		}
	}
	if (bytes_read == -1)
	{
		perror("Error");
		free(buffer);
		return (1);
	}
	free(buffer);
	return (0);
}
