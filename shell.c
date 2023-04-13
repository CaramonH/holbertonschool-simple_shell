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
