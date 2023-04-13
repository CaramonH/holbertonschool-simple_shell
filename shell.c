#include "hell.h"
#define MAX_ARGS 100
/**
 *main - the main func for our simple shell
 *upon running the program this will display a $ and wait for input
 *once it recieves input it will fork and deliver it to split string
 *Return: either 0 if pass or -1 if fail
 */

int main(void)
{
	char *command = NULL;
	size_t size = 0;
	char **words = NULL;
	int count;
	int CoP;

	while (1)
	{
		if (isatty(STDIN_FILENO))
            		write(STDOUT_FILENO, "$ ", 2);
		if (getline(&command, &size, stdin) == -1)
			exit(EXIT_SUCCESS);
		if (command[0] == '\n')
			continue;
		words = split_string(command, &count);
		if (strcmp(words[0], "/bin/exit") == 0)
		{
			free(words);
			free(command);
			exit(EXIT_SUCCESS);
		}

		if (access(words[0], X_OK) == 0)
		{
			CoP = fork();
			if (CoP == 0)
			{
				if (execve(words[0], words, NULL) == -1)
					return (-1);
				return (0);
			}
			else
				wait(NULL);
		}
		else
			perror("Command Error");
	}
}

/**
 *split_string - this function splits the input string and
 *makes sure it is malloced and counted
 *@str:the string that we need to tokenize and output
 *@count: the full length of the string
 *Return: the result var that stores the tokenized string
 */

char **split_string(char *str, int *count)
{
	char *token;
	char *words[MAX_ARGS];
	char **result;
	int i = 0;
	int c;
	char *cmd;

	token = strtok(str, " \n");
	while (token != NULL && i < MAX_ARGS)
	{
		if (i == 0 && token[0] != '/')
		{
			cmd = malloc(strlen("/bin/") + strlen(token) + 1);
			if (cmd == NULL)
			{
				perror("malloc error");
				free(cmd);
				exit(EXIT_FAILURE);
			}
			/*malloc for the space of /bin/ in cmd*/
			strcpy(cmd, "/bin/");
			strcat(cmd, token);
			words[i] = cmd;
		}
		else
		{
			words[i] = token;
		}
		i++;
		token = strtok(NULL, " \n");
	}
	*count = i;
	/*malloc for the space of the string into result*/
	result = malloc((i + 1) * sizeof(char *));
	if (result == NULL)
	{
		perror("malloc error");
		exit(EXIT_FAILURE);
	}
	for (c = 0; c < i; c++)
	{
		result[c] = words[c];
	}
	result[i] = NULL;
	if (cmd != NULL && i == 0 && token[0] != '/')
		free(cmd);
	return (result);
}
