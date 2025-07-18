/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:57:20 by salsoysa          #+#    #+#             */
/*   Updated: 2025/07/18 16:08:36 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	_heredoc_util(t_data *d, int fd, const char *name, char *eof)
{
	int	fdr;

	if (!heredoc_read(d, fd, eof))
	{
		close(fd);
		unlink(name);
		return (-1);
	}
	close(fd);
	fdr = open(name, O_RDONLY);
	if (fdr >= 0)
		unlink(name);
	return (fdr);
}

char	*_random_file_name(char *dst, size_t len)
{
	int		fd;
	char	buffer[25];
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	fd = open("/dev/urandom", O_RDONLY);
	if (fd < 0)
		return (NULL);
	if (!read(fd, buffer, 25))
	{
		close(fd);
		return (0);
	}
	close(fd);
	while (i < sizeof(buffer) && j < len - 1)
	{
		if (ft_isalnum(buffer[j]))
			dst[i++] = buffer[j];
		j++;
	}
	return (dst);
}
