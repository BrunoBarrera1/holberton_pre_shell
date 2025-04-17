#include "shell.h"

/**
 * main - Entry function of shell.
 *
 * @argc:
 * @argv:
 * @env:
 *
 * Return: 0.
 */

int main(int argc __attribute__((__unused__)), char **argv, char **envp)
{
	char **args = check_validity(get_line());

	for (;;)
	{
		if (args == NULL)
		{
			free_all(args);
			continue;
		}

		interpreter(args, envp);

		free_all(args);

	}
	return (SUCCESS);
}
