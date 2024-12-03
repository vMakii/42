/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:59:11 by mivogel           #+#    #+#             */
/*   Updated: 2024/12/03 17:30:50 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read(int fd, char *buffer)
{
	char	*tmp;
	int		i;

	tmp = (char *)malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	while (!ft_strchr(buffer, '\n'))
	{
		i = read(fd, tmp, BUFFER_SIZE);
		if (i <= 0)
			break ;
		tmp[i] = '\0';
		buffer = ft_strjoin(buffer, tmp);
	}
	free(tmp);
	if (i < 0)
		return (NULL);
	return (buffer);
}

static char	*ft_line(char **buffer)
{
	char	*line;
	char	*tmp;
	char	*nl;
	size_t	len;

	if (!*buffer || **buffer == '\0')
		return (NULL);
	nl = ft_strchr(*buffer, '\n');
	if (nl)
	{
		len = nl - *buffer + 1;
		line = ft_strdup(*buffer);
		line[len] = '\0';
		tmp = ft_strdup(nl + 1);
		free(*buffer);
		*buffer = tmp;
	}
	else
	{
		line = ft_strdup(*buffer);
		free(*buffer);
		*buffer = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	return (ft_line(&buffer));
}
//
// #include <fcntl.h>
// #include <stdio.h>
//
// int	main(void)
// {
// 	int		fd;
// 	char	*line;
//
// 	fd = open("test.txt", O_RDONLY);
// 	if (fd < 0)
// 		return (1);
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// 	return (0);
// }
