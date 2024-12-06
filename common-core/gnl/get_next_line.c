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

static char *read_and_store(int fd, char *remainder)
{
    char *buffer;
    ssize_t bytes_read;

    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);
    bytes_read = 1;
    while (!ft_strchr(remainder, '\n') && bytes_read > 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == -1)
        {
            free(buffer);
            return (NULL);
        }
        buffer[bytes_read] = '\0';
        remainder = ft_strjoin(remainder, buffer);
    }
    free(buffer);
    return (remainder);
}

static char *extract_line(char **remainder)
{
    char *line;
    char *tmp;
    char *newline_pos;

    if (!*remainder || **remainder == '\0')
        return (NULL);
    newline_pos = ft_strchr(*remainder, '\n');
    if (newline_pos)
    {
        line = malloc(sizeof(char) * (newline_pos - *remainder + 2));
        if (!line)
            return (NULL);
        for (size_t i = 0; i <= (size_t)(newline_pos - *remainder); i++)
            line[i] = (*remainder)[i];
        line[newline_pos - *remainder + 1] = '\0';
        tmp = ft_strdup(newline_pos + 1);
        free(*remainder);
        *remainder = tmp;
    }
    else
    {
        line = ft_strdup(*remainder);
        free(*remainder);
        *remainder = NULL;
    }
    return (line);
}

char *get_next_line(int fd)
{
    static char *remainder;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    remainder = read_and_store(fd, remainder);
    if (!remainder)
        return (NULL);
    line = extract_line(&remainder);
    if (!line && remainder)
    {
        free(remainder);
        remainder = NULL;
    }
    return (line);
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
