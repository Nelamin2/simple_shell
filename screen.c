#include "smpshell.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * screen - printing function
 *@line: output to be displayed
 */
void screen(const char *line)
{
write(STDOUT_FILENO, line, strlen(line));
}

