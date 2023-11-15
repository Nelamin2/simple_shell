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
void screen(const char *line);
char *read_line(void)
{
char *line;
size_t size = 0;
if (getline(&line, &size, stdin) == -1)
{
perror("Error reading input");
exit(EXIT_FAILURE);
}
else
{
if (feof(stdin))
{screen("\n");
exit(EXIT_SUCCESS);
}
return (line);
}
}
