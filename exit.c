#include "hell.h"
/**
 *exit_cmd - please leave
 *@words: what even are these
 *Return: nothin
 */

void exit_cmd(char *words)
{
		free_them;
		exit(EXIT_SUCCESS);
}
/**
 *free_them - let them ouuuut
 *@words: are made up by humans
 *@command: dont touch that
 *Return: no return
 */
void free_them(char *words, char *command)
{
	free(words);
	free(command);
}
