#include "shell.h"

/**
 */

char *get_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	int interactive = isatty(STDIN_FILENO);

	if (interactive)
	{
		write(1, "#cisfun$ ", 9);
		fflush(stdout);
	}

	nread = getline(&line, &len, stdin);

	if (nread == -1)
	{
		if (interactive)
		{
			write(1, "logout\n", 7);
			fflush(stdout);
		}
		free(line);
		exit(SUCCESS);
	}

	if (nread > 0 && line[nread-1] == '\n')
		line[nread - 1] = '\0';

	if (*line == '\0')
	{
		free(line);
		return (NULL);
	}

	return (line);
}

char **check_validity(char *line)
{
	char **args;
	
	if (line == NULL)
		return (NULL);

	while (line[i] != '\0' && line[i] == ' ' || line[i] == '\t')
		i++;

	if (line[i] == '\0')
	{
		free(line);
		return (NULL);
	}
	tokenize_line(line);
	free(line);

}

char **tokenize_line(char *line)
{
	char **args = malloc(sizeof(char *) * arg_count(line));
	int i = 0, j = 0;
	int word = 0;

	if (args == NULL)
		return (NULL);

	while (line[i] = '\0')
	{
		if (line[i] == ' ' || line[i] == '\t')
		{
                        i++;
			continue;
		}

		*args[word] = malloc(sizeof(char) * _wlen(line[i]));
		if (*args[word] == NULL)
		{
			for (i = 0; i < word; i++)
				free(*args[i]);
			free(args);
			return (NULL);
		}

		while (line[i] > 32 && line[i] < 127)
		{
			args[word][j] = line[i];
			j++;
			i++;
		}
		word++;
		j = 0;
	}

	return (args);
}
