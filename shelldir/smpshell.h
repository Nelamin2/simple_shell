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
#include <errno.h>
#include "builtin.h"

void prompt_always_on(void);
char *read_line(void);
char *rm_nline(char *line);
char *parse_line(char *line);
void perform_exit(int status);
void run_command(char **path, char *file);
char *compose_path(char *token, char *ph);
void screen(const char *line);
char *ggetline(void);
void handle_path(const char *action, const char *directory);
extern char **environ;
extern char **env_var;
int xatoi(char *s);
void memory_free2(char **p);
void memory_free(char *p);
int xisalpha(int c);
int xstrcmp(char *s1, char *s2);
int xputchar(char c);
char *xstrncpy(char *dest, char *src, int n);
char *xstrncat(char *dest, char *src, int n);
int xstrlen(char *s);
char *xstrdup(char *str);
char *xstrstr(char *haystack, char *needle);
char *xstrchr(char *s, char c);
#endif
