#include "smpshell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * run_command - evokes the shell
 * @line: input command
 */
void run_command(const char *line[])
{
pid_t child_pid = fork();
if (child_pid < 0)
{
perror("Fork error");
exit(EXIT_FAILURE);
}
else if (child_pid == 0)
{
if (execve(line[0], (char *const *)line, NULL) == -1)
perror("Execve failed");
exit(EXIT_FAILURE);
}
else
{wait(NULL);
}
return (0);
}
