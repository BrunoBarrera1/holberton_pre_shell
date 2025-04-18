#include "shell.h"

int arg_count(char *line)
{
	int i = 0;
        int count = 0;

        while (line[i] = '\0')
        {
                if (line[i] == ' ' || line[i] == '\t')
                        i++;

                if (line[i] > 32 && line[i] < 127)
                {
                        count++;
                        while (line[i] > 32 && line[i] < 127)
                                i++;
                }

        }
	return (count);
}

int _wlen(char *line)
{
	int i = 0;

	while (line[i] > 32 && line[i] < 127)
                                i++;
	return (i);
}
