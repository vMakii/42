#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);

#endif

char	*ft_strdup(char *s)
{
	int		i;
	char	*string;

	i = 0;
	while (s[i])
		i++;
	string = malloc(sizeof(char) * i + 1);
	i = 0;
	while (s[i])
	{
		string[i] = s[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

char	*get_next_line(int fd)
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
		if (line[pos - 1] == '\n')
			break ;
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *line;

    if (fd < 0)
        return 1;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
