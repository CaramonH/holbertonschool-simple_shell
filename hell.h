#ifndef MAIN_H
#define MAIN_H

/* Standard Libraries */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>


char **split_string(char *str, int *count);
int main(void);
list_t *add_node(list_t **head, const char *str);
list_t *add_node_end(list_t **head, const char *str);
list_t *insert_node_at_index(list_t **head, unsigned int idx, char *str);

#endif
