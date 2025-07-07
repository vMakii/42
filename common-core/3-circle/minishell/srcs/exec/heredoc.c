/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:04:45 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/07 10:50:40 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_delimiter_match(char *str, char *delimiter)
{
	if (ft_strncmp(str, delimiter, ft_strlen(delimiter)) == 0
		&& ft_strlen(str) == ft_strlen(delimiter))
		return (true);
	return (false);
}

static bool	handle_heredoc_eof_error(t_data *data, char *str, char *delimiter)
{
	free(str);
	if (g_sig == SIGINT_HEREDOC)
		return (false);
	ft_putstr_fd("minishell: warning:", 2);
	ft_putstr_fd("here-document delimited by end-of-file (wanted `", 2);
	ft_putstr_fd(delimiter, 2);
	ft_putstr_fd("')\n", 2);
	data->exit_status = 0;
	return (true);
}

static bool	heredoc_read(t_data *data, int fd, char *delimiter)
{
	char	*str;

	while (1)
	{
		write(1, "> ", 2);
		str = ft_readline();
		if (g_sig == SIGINT_HEREDOC || !str)
			return (handle_heredoc_eof_error(data, str, delimiter));
		if (is_delimiter_match(str, delimiter))
		{
			free(str);
			break ;
		}
		str = ft_expand(data, str);
		write(fd, str, ft_strlen(str));
		write(fd, "\n", 1);
		free(str);
	}
	return (true);
}

static int	ft_handle_heredoc(t_data *data, char *eof)
{
	int		fd;
	char	filename[256];
	char	*index_str;

	index_str = ft_itoa(data->heredoc_i++);
	if (!index_str)
		return (-1);
	ft_strlcpy(filename, ".heredoc", sizeof(filename));
	ft_strlcat(filename, index_str, sizeof(filename));
	ft_strlcat(filename, ".tmp", sizeof(filename));
	free(index_str);
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		return (-1);
	if (!heredoc_read(data, fd, eof))
	{
		close(fd);
		unlink(filename);
		return (-1);
	}
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd >= 0)
		unlink(filename);
	return (fd);
}

bool	ft_prepare_heredocs(t_data *data)
{
	t_cmd	*tmp;

	tmp = data->cmd;
	if (!tmp)
		return (-1);
	while (tmp)
	{
		if (tmp->type == HEREDOC)
		{
			ft_set_signal(data, IN_HEREDOC);
			data->heredoc_fd = ft_handle_heredoc(data, tmp->str);
			if (data->heredoc_fd == -1)
			{
				data->exit_status = 130;
				ft_set_signal(data, BASE_CASE);
				return (0);
			}
		}
		tmp = tmp->next;
	}
	ft_set_signal(data, BASE_CASE);
	return (1);
}
