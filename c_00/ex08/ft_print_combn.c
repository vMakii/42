//42 header
#include <unistd.h>

void	ft_combn(char t[], int n, int index, int start)
{
	int	i;

	if (n == index)
	{
		write(1, t, n);
		if (t[0] != '9' - n + 1 || t[n - 1] != '9')
			write(1, ", ", 2);
		return ;
	}
	i = start;
	while (i <= '9')
	{
		t[index] = i;
		ft_combn(t, n, index + 1, i + 1);
		i++;
	}
}

void	ft_print_combn(int n)
{
	char	t[10];

	if (n < 1 || n > 9)
		return ;
	ft_combn(t, n, 0, '0');
}
