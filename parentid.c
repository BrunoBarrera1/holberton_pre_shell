#include <stdio.h>
#include <unistd.h>

/**
 * main - PPID
 * Return: 0
 */
int main(void)
{
	pid_t pid;

	pid = getppid();

	printf("%d\n", pid);
	return 0;
}
