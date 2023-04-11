#include "hell.h":wq
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
	int i = 0;
	int CoP;

	while (1)
	{
		printf("$ ");
		getline(&command, &size, stdin);
		words = split_string(command, &count);

		if (strcmp(words[0], "/bin/exit") == 0)
			break;

		for (; i < count ; i++)
			printf("token %d: %s\n", i, words[i]);
		CoP = fork();

		if (CoP == 0)
		{
			if (execve(words[0], words, NULL) == -1)
			{
				perror("Error");
				return (-1);
			}
			return (0);
		}
		else
		{
			wait(NULL);
		}
	}
	return (0);
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
			/*malloc for the space of /bin/ in cmd*/
			cmd = malloc(strlen("/bin/") + strlen(token) + 1);
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
	for (c = 0; c < i; c++)
		result[c] = words[c];
	result[i] = NULL;

	return (result);
}
