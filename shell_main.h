#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>


char *read_the_line_cmd();
void execute_function_cmd(char **cmd, char **env);
char **line_diviser(char *line);
char **getfullpath(const char *command);

#endif

