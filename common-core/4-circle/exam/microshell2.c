#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void ft_putstr(char *str)
{
    int i = 0;
    while (str[i])
    {
        write(2, &str[i], 1);
        i++;
    }
}

void cd(char **argv, int i)
{
    if (i != 2)
        return (ft_putstr("error: cd: bad arguments\n"));
    if (chdir(argv[1]) == -1)
    {
        ft_putstr("error: cd: cannot change directory to ");
        ft_putstr(argv[1]);
        ft_putstr("\n");
        return ;
    }
}

void    exec(char **argv, int i, char **envp)
{
    int is_pipe = 0;
    int fd[2];
    int pid;

    if (argv[i] && !strcmp(argv[i], "|"))
        is_pipe = 1;
    if (is_pipe && pipe(fd) == -1)
        return (ft_putstr("error: fatal 1\n"));
    pid = fork();
    if (pid == -1)
        return (ft_putstr("error: fatal 2\n"));
    if (pid == 0)
    {
        argv[i] = 0;
        if (is_pipe)
        {
            if (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1)
                return (ft_putstr("error: fatal 3\n"));
        }
        execve(argv[0], argv, envp);
        ft_putstr("error: cannot execute ");
        ft_putstr(argv[0]);
        ft_putstr("\n");
        return ;
    }
    waitpid(pid, 0, 0);
    if (is_pipe)
    {
        if (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1)
            return (ft_putstr("error: fatal 4\n"));
    }
}

int main(int argc, char **argv, char **envp)
{
    int i = 0;
    if (argc > 1)
    {
        while (argv[i] && argv[++i])
        {
            argv += i;
            i = 0;
            while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
                i++;
            if (!strcmp(argv[0], "cd"))
                cd(argv, i);
            else if (i)
                exec(argv, i, envp);
        }
    }
    return (0);
}