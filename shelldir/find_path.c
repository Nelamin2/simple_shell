#include "smpshell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/stat.h>
/**
 * path_tracker- find teh corrct directory
 * @ine: the comand to ftnd the poath for
 * Return: NULL.
 */
 char *path_tracker(const char *command)
{
size_t j;
char *direction; 
char *cpdirection;
const char *delimiter = ":";
char *path;
struct stat buffer;
char *token;
path = NULL;
direction = getenv("PATH");
if (direction == NULL) {
fprintf(stderr, "PATH environment variable not found\n");
return NULL;
}
cpdirection = strdup(direction);
if (cpdirection == NULL)
{
perror("Memory allocation error");
exit(EXIT_FAILURE);
}
token = strtok(cpdirection, delimiter);
while (token != NULL)
{
printf("Command: %s\n", command);
path = malloc(strlen(token) + strlen(command) + 2);
if (path == NULL)
{
perror("Memory allocation error");
free(cpdirection);
exit(EXIT_FAILURE);
}
sprintf(path, "%s/%s", token, command);
  printf("Command Bytes: ");
        for (j = 0; j < strlen(command); ++j) {
            printf("%02X ", (unsigned char)command[j]);
        }
        printf("\n");

        printf("Path Bytes: ");
        for (j = 0; j < strlen(path); ++j) {
            printf("%02X ", (unsigned char)path[j]);
        }
        printf("\n");
	printf("Checking path: %s\n", path);
if (stat(path, &buffer) == 0)
{
free(cpdirection);
return (path);
}
else
{
perror("Error in stat");
free(path);
path = NULL;
token = strtok(NULL, delimiter);
}
}
free(cpdirection);
return (NULL);
}
