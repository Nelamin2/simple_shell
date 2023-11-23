#include "smpshell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "builtin.h"
int run_command(char **path,  char *file)
{
int status;
pid_t child_pid;
child_pid = fork();
if (child_pid < 0)
{
perror("Fork error");
exit(EXIT_FAILURE);
}
else if (child_pid == 0)
{
if (strncmp(path[0], "./", 2) && strncmp(path[0], "/", 1))
{
path_tracker(path);
}
if (execve(path[0], path, environ) == -1)
{
perror(file);
memory_free2(path);
exit(EXIT_FAILURE);
}
}
else
{
wait(&status);
if (WIFEXITED(status))
return (WEXITSTATUS(status));
}
return (0);
}
