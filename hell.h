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
extern char **environ;

/* Prototypes */

/* built-in */
void print_environment(void);

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
