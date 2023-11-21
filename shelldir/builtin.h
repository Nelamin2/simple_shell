#ifndef BUILTIN_H
#define BUILTIN_H

#include "smpshell.h"
#include "env.h"

typedef struct builtinz
{
	char *command;
	int (*p)(char **, int, char *);
} builtinz;

int benv(char **cmd, int status, char *filename)
int (*bring_builtin(char **command))(char **, int, char *)
builtinz built-inspec(char *command)
extern char **env_var;
extern char **environ;


#endif
