#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * interpreter -
 * @args:
 * @env:
 */
void interpreter(char **args, char **env)
{
	pid_t pid;
	int status;
	char *cmd;

	cmd = path(args[0]);
	if (!cmd)
	{
		fprintf(stderr, "%s: command not found\n", args[0])
			return;
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(cmd, args, env) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
	}
	else
	{
		perror("fork");
	}
}
