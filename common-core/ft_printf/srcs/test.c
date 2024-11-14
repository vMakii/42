#include <stdio.h>

int	main(void)
{
	int	i;

	i = 2;
	if (i++ == 3)
	{
		printf("oui : %d", i);
		return (0);
	}
	printf("non : %d", i);
}
