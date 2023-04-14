#include "hell.h"
#define MAX_ARGS 100
/**
 *split_string - this function splits the input string and
 *makes sure it is malloced and counted
 *@str:the string that we need to tokenize and output
 *Return: the result var that stores the tokenized string
 */

char **split_string(char *str)
{
	char *token;
	char *words[MAX_ARGS];
	char **result;
	int i = 0;
	int c;
	char *cmd;
	char *path = NULL;
	char *paths[20];

	path = getenv("PATH");
	tokenize_path(path, paths);

	token = strtok(str, " \n");
	while (token != NULL && i < MAX_ARGS)
	{
		if (i == 0 && token[0] != '/')
		{
			cmd = malloc(_strlen(paths[i]) + _strlen(token) + 1);
			strcpy(cmd, "/bin/");
			strcat(cmd, token);
			words[i] = cmd;
		}
		else
			words[i] = token;
		i++;
		token = strtok(NULL, " \n");
	}
	result = malloc((i + 1) * sizeof(char *));
	if (result == NULL)
	{
		perror("malloc error");
		exit(EXIT_FAILURE);
	}
	for (c = 0; c < i; c++)
		result[c] = words[c];
	result[i] = NULL;
	if (cmd != NULL && i == 0 && token[0] != '/')
		free(cmd);
	return (result);
}
