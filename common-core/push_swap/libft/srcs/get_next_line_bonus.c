/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:25:20 by mivogel           #+#    #+#             */
/*   Updated: 2024/11/29 11:15:19 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_join_free(char *buffer, char *tmp)
{
	char	*dst;

	dst = ft_strjoin(buffer, tmp);
	free(buffer);
	return (dst);
}

static char	*ft_read(int fd, char *buffer)
{
	char	*tmp;
	int		i;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	i = 1;
	while (i > 0)
	{
		i = read(fd, tmp, BUFFER_SIZE);
		if (i == -1)
		{
			free(tmp);
			free(buffer);
			return (NULL);
		}
		tmp[i] = 0;
		buffer = ft_join_free(buffer, tmp);
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	free(tmp);
	return (buffer);
}

static char	*ft_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

static char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(*buffer));
	if (!line)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*get_next_line_bonus(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = ft_read(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_line(buffer[fd]);
	buffer[fd] = ft_next(buffer[fd]);
	return (line);
}
//
// #include <fcntl.h>
// #include <stdio.h>
//
// int	main(void)
// {
// 	int		fd;
// 	int		fd2;
// 	char	*line;
// 	char	*line2;
//
// 	fd = open("test.txt", O_RDONLY);
// 	fd2 = open("test2.txt", O_RDONLY);
// 	if (fd < 0 || fd2 < 0)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}
// 	line = get_next_line(fd);
// 	line2 = get_next_line(fd2);
// 	while (line && line2)
// 	{
// 		printf("fd1 :%s", line);
// 		printf("fd2 :%s", line2);
// 		line = get_next_line(fd);
// 		line2 = get_next_line(fd2);
// 	}
// 	close(fd);
// 	close(fd2);
// 	return (0);
// }
