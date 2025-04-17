#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT 1024 /*max buffer size*/

int main()
{
	char input[MAX_INPUT];
	pid_t pid;

	while (1)
	{
		printf("#cisfun$ ");

		if (fgets(input, MAX_INPUT, stdin) == NULL)
		{
			break;
		}

		input[strcspn(input, "\n")] = '\0';
		
		if (strlen(input) == 0) continue;

		pid_t pid = fork();

		if (pid == 0)
		{
			char *args[] = {input, NULL};
			execve(input, args, NULL);

			perror("execve");
			exit(EXIT_FAILURE);
		}
		else if (pid > 0)
			wait(NULL);
		else
			perror("fork");
	}

	return (0);
}
	
