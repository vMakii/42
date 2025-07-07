/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:25:11 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/03 13:00:09 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*append_char_to_line(char *line, char c)
{
	char	buf[2];
	char	*tmp;

	buf[0] = c;
	buf[1] = '\0';
	tmp = ft_strjoin(line, buf);
	if (!tmp)
	{
		free(line);
		return (NULL);
	}
	free(line);
	return (tmp);
}

char	*ft_readline(void)
{
	char	buf;
	char	*line;
	ssize_t	bytes;

	line = ft_strdup("");
	if (!line)
		return (NULL);
	bytes = read(0, &buf, 1);
	while (bytes > 0)
	{
		if (buf == '\n')
			break ;
		line = append_char_to_line(line, buf);
		if (!line)
			return (NULL);
		bytes = read(0, &buf, 1);
	}
	if ((bytes <= 0 && *line == '\0') || !line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
