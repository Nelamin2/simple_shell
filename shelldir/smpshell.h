#ifndef SMPSHELL_H_
#define SMPSHELL_H_

#include <stdio.h>
#include <unistd.h>
#include <ucontext.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>
#include <sys/wait.h>
#include "builtin.h"
#include "env.h"

void prompt_always_on(void);
char *read_line(char *line);
void perform_exit(int status);
void run_command(const char *line);
void parse_line(const char *line, char *arguments[]);
char *path_tracker(const char *command);
void screen(const char *line);
extern char **environ;
extern char **env_var;
#endif
