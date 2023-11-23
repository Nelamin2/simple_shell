#include "smpshell.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * screen - printing function
 *@line: output to be displayed
 */
void screen(char *line)
{
write(STDOUT_FILENO, line, strlen(line));
}
