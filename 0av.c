#include <stdio.h>

int main(int ac, char **av)
{
	(void)ac;

	for (char **arg = av; *arg != NULL; arg++)
	{
		printf("%s\n", *arg);
	}

	return (0);
}
