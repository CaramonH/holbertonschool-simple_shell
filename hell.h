#ifndef MAIN_H
#define MAIN_H

/* Standard Libraries */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

/* Prototypes */

/* built-in */
void func_printenv(char **env);

/* strings */
void _puts(char *str);
int _strlen(const char *s);
int _putchar(char c);
char *str_concat(char *s1, char *s2);
int _strcmp(char *s1, char *s2);

/* shell */
char **split_string(char *str, int *count);
int main(void);

#endif
