#ifndef SMPSHELL_H_
#define SMPSHELL_H_

#define MAX_PATH_LENGTH 1024
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
int is_whitespace(const char *str);
char *rm_nline(char *line);
char **parse_line(char *line);
int path_tracker(char **path);
void perform_exit(int status);
int  run_command(char **path, char *file);
char *compose_path(char *token, char *ph);
char *xstrcat(char *dest, char *src);
int bexit(char **command, int status, char *file);
int benv(char **cmd, int status, char *file);
void screen(char *line);
char *ggetline(void);
void handle_path(char *action, char *directory);
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
