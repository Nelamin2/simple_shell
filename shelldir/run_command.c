#include "smpshell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "env.h"
#include "builtin.h"
void run_command(const char *line)
{
char *path;
char *arguments[20];
pid_t child_pid = fork();
int i;
size_t j;
if (child_pid < 0)
{
perror("Fork error");
exit(EXIT_FAILURE);
}
else if (child_pid == 0)
{
printf("Line Bytes: ");
printf("Line Bytes: ");
for (i = 0; line[i] != '\0'; i++)
{
printf("%02X ", (unsigned char)line[i]);
}
printf("\n");
parse_line(line, arguments);
printf("Command: %s\n", arguments[0]);
if (setenv("MY_VARIABLE", "Hello, World!", 1) != 0)
{
perror("Error setting environment variable");
exit(EXIT_FAILURE);
}
printf("Command Bytes: ");
for (j = 0; j < strlen(arguments[0]); ++j)
{
printf("%02X ", (unsigned char)arguments[0][j]);
}
printf("\n");
path = path_tracker(arguments[0]);
printf("Child process about to execute: %s\n", path);
printf("Arguments:");
for (i = 0; arguments[i] != NULL; ++i)
{
printf(" %s", arguments[i]);
}
printf("\n");
execvp(path, arguments);
perror("Error in execve");
exit(EXIT_FAILURE);
}
else
{
int status;
waitpid(child_pid, &status, 0);
if (WIFEXITED(status)) {
printf("Child process exited with status %d\n"
, WEXITSTATUS(status));
}
else
{ printf("Child process did not exit normally\n");}
}
}
