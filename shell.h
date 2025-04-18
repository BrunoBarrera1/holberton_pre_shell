#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SUCCESS 0  /* Define SUCCESS */
#define MAX_INPUT 1024  /* Define max input size */

/* Function prototypes */
char *get_line(void);
char **check_validity(char *line);
void free_all(char **args);
void interpreter(char **args, char **envp);
char **tokenize_line(char *line);
int arg_count(char *line);
int _wlen(char c);
int is_interactive(void);
void free_all(char **args);
void interpreter(char **args, char **envp);

#endif /* SHELL_H */

