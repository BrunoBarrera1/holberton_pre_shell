#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *line = NULL; /*pointer to store user input*/
	size_t size = 0; /*stores current allocated buffer*/
	ssize_t nread; /*stores num of chars read from user input*/

	while (1) // infinite loop that keeps reading user input
	{
		printf("$ "); /*print prompt*/

		nread = getline(&line, &size, stdin); /*read input from user*/
		if (nread == -1) /*handle errors or eqf ctrl+D*/
		{
			perror("getline");
			free(line);
			exit(EXIT_FAILURE);
		}

		printf("you entered: %s", line); /*print input back*/
	}

	free(line);
	return 0;
}

