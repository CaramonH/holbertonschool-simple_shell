#ifndef MAIN_H
#define MAIN_H

/* Standard Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>


/**
 * struct list_s - singly linked list
 * @str: string
 * @next: next node pointer
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	char *str;
	struct listy_s *next;
} list_t;

/* Prototypes */
list_t *add_node(list_t **head, const char *str);
list_t *add_node_end(list_t **head, const char *str);
list_t *insert_node_at_index(list_t **head, unsigned int idx, char *str);
#endif
