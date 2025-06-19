#include "get_next_line.h"

static char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*string;

	i = 0;
	while (s[i])
		i++;
	string = malloc(sizeof(char) * (i + 1));
	if (!string)
		return (NULL);
	i = 0;
	while (s[i])
	{
		string[i] = s[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

char	*gnl(int fd)
{
	static char buffer[BUFFER_SIZE];
	static char line[70000];
	static int buffer_pos = 0;
	static int pos = 0;
	int i = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buffer_pos <= pos)
		{
			buffer_pos = read(fd, buffer, BUFFER_SIZE);
			pos = 0;
			if (buffer_pos <= 0)
				break ;
		}
		line[i++] = buffer[pos++];
		if (line[pos - 1] == '\n' || (size_t)i >= sizeof(line))
			break ;
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}