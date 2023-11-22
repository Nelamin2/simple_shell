#ifndef BUILTIN_H
#define BUILTIN_H

#include "smpshell.h"

typedef struct builtinz
{
	char *command;
	int (*p)(char **, int, char *);
} builtinz;

int benv(char **cmd, int status, char *file);
int (*bring_builtin(char **command))(char **, int, char *)
builtinz built_inspec(char *command);


#endif
