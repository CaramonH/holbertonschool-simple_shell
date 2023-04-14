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

/* strings */
void _puts(char *str);
int _strlen(const char *s);
int _putchar(char c);
char *str_concat(char *s1, char *s2);
int _strcmp(char *s1, char *s2);

/* shell */
char **split_string(char *str);
void free_them(char *words, char *command);
void exit_cmd(char *words);
int main(void);
char *tokstr(char *str, const char *delim, char **saveptr);
char *_strpbrk(char *s, const char *accept);
int cleanstr(char *line);
unsigned int _strspn(char *s, const char *accept);
char *_strcat(char *dest, char *src);
char *_strchr(const char *s, char c);
int _strncmp(char *s1, char *s2, int n);
char *_strcpy(char *dest, char *src);
void tokenize_path(char *path, char **paths);

#endif
