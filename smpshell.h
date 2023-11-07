#ifndef SMPSHELL_H_
#define SMPSHELL_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

void screen(const char *line);
void prompt_always_on(void);
void run_command(const char *line);
void read_line(char *line);
#endif
