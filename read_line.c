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

void read_line(char *line)
{ 
if (fgets(line, sizeof(line), stdin) == NULL)
{
if (feof(stdin))
screen("\n");
exit(EXIT_SUCCESS);
}
else
{
screen("reading input failed");
exit(EXIT_FAILURE);
}
}
