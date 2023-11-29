#ifndef BUILTIN_H
#define BUILTIN_H

#include "smpshell.h"

/**
 * struct builtinz - Structure for builtin commands
 * @command: the command's name
 * @p: the corresponding  function to handle  command
 */

typedef struct builtinz
{
	char *command;
	int (*p)(char **, int, char *);
} builtinz;

int benv(char **cmd, int status, char *file);
int (*bring_builtin(char **command))(char **args, int status, char *filename);
builtinz built_inspec(char *command);


#endif
