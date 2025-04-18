#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **copy_env(char **env)
{
	int i, count = 0;
	char **new_env;

	while (env[count] != NULL)
		count++;

	new_env = malloc((count + 1) * sizeof(char *));
	if (new_env == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < count; i++)
	{
		new_env[i] = strdup(env[i]);
		if (new_env[i] == NULL)
		{
			perror("strdup");

			while (i > 0)
			{
				free(new_env[--i]);
			}
			free(new_env);
			exit(EXIT_FAILURE);
		}
	}
	new_env[count] = NULL;

	return (new_env);
}

