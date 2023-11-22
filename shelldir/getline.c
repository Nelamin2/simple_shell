#include <stdio.h>
#include <unistd.h>
#include <ucontext.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>
#include <sys/wait.h>
#include "builtin.h"

#define BUFFER_SIZE 1024 
char *ggetline()
{
char *line;
char *endline;
size_t length;
char buffer[BUFFER_SIZE];
size_t size;
size_t cursor;
cursor = 0;
size =0;
if (cursor == 0)
{
size = read(0, buffer, BUFFER_SIZE);
if (size == 0)
{
return NULL;
}
}
endline = xstrchr(buffer + cursor, '\n');
if (endline != NULL)
{
length = endline - (buffer + cursor) + 1;
line = malloc(length);
if (line == NULL)
{
perror("Memory allocation error");
exit(EXIT_FAILURE);
}
xstrncpy(line, buffer + cursor, length - 1);
line[length - 1] = '\0';
cursor += length;
return (line);
}
else
{
line = malloc(size - cursor + 1);
if (line == NULL) {
perror("Memory allocation error");
exit(EXIT_FAILURE);
}
strncpy(line, buffer + cursor, size - cursor);
line[size - cursor] = '\0';
cursor = 0;
return (line);
}
return (NULL);
}

