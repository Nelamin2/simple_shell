#include "smpshell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * read_line - read user's input
 *@line: input string
 *
 *
 */
void screen(char *line);
char *read_line(void)
{
char *line = NULL;
int chars_read;
size_t size = 0;
chars_read = getline(&line, &size, stdin);
if (chars_read == -1)
{
perror("Error reading input");
exit(EXIT_FAILURE);
}
if (line[chars_read - 1] == '\n')
{
line[chars_read - 1] = '\0';
}
return (line);
}
