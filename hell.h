#ifndef MAIN_H
#define MAIN_H

/* Standard Libraries */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * struct list_s - singly linked list
 * @str: string - malloc'd string
 * @next: pointer to the next node
 *
 * Description:: singly linked list node structure
 */
typedef struct list_s
{
	char *str
		struct list_s *next;
} list_t;

char **split_string(char *str, int *count);
int main(void);
list_t *add_node(list_t **head, const char *str);
list_t *add_node_end(list_t **head, const char *str);
list_t *insert_node_at_index(list_t **head, unsigned int idx, char *str);

#endif
