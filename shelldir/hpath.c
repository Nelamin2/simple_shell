#include <stdio.h>
#include <unistd.h>
#include <ucontext.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>
#include <sys/wait.h>
#include "builtin.h"

#define MAX_PATH_LENGTH 1024
#define MAX_COMMAND_LENGTH 1024

void handle_path(char *action, char *directory)
{
char *dir;
char new_path[MAX_PATH_LENGTH];
char *path_copy;
char full_path[MAX_PATH_LENGTH + MAX_COMMAND_LENGTH];
char *current_path;
current_path = getenv("PATH");
if (xstrcmp(action, "add") == 0) 
{
if (current_path == NULL) 
{
setenv("PATH", directory, 1);
}
else
{
snprintf(new_path, sizeof(new_path), "%s:%s", current_path, directory);
setenv("PATH", new_path, 1);
}
write(STDOUT_FILENO, "Added ", 6);
write(STDOUT_FILENO, directory, strlen(directory));
write(STDOUT_FILENO, " to PATH.\n", 10);
} 
else if (xstrcmp(action, "remove") == 0)
{
if (current_path != NULL)
{
char *path_in_path = xstrstr(current_path, directory);
if (path_in_path != NULL)
{
strncpy(new_path, current_path, path_in_path - current_path - 1);
strcat(new_path, path_in_path + xstrlen(directory));
setenv("PATH", new_path, 1);
write(STDOUT_FILENO, "Removed ", 8);
write(STDOUT_FILENO, directory, xstrlen(directory));
write(STDOUT_FILENO, " from PATH.\n", 12);
}
else
{
write(STDOUT_FILENO, directory, xstrlen(directory));
write(STDOUT_FILENO, " is not in PATH.\n", 17);
}
}
else
{
write(STDOUT_FILENO, "PATH is not set.\n", 17);
}
}
else if (xstrcmp(action, "search") == 0) 
{
if (current_path != NULL) {
path_copy = strdup(current_path);
if (path_copy == NULL) {
perror("Memory allocation error");
exit(EXIT_FAILURE);
}
dir = strtok(path_copy, ":");
while (dir != NULL)
{
snprintf(full_path, sizeof(full_path), "%s/%s", dir, directory);
if (access(full_path, X_OK) == 0) 
{
write(STDOUT_FILENO, "Executable found: ", 18);
write(STDOUT_FILENO, full_path, xstrlen(full_path));
write(STDOUT_FILENO, "\n", 1);
free(path_copy);
}
dir = strtok(NULL, ":");
}
write(STDOUT_FILENO, "Executable not found in PATH.\n", 30);
free(path_copy);
}
else
{
write(STDOUT_FILENO, "PATH is not set.\n", 17);
}
}
}
