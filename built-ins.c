/**
 * exit_cmd - pulls free_them and exits
 * @words - words to be freed
 */
void exit_cmd(char *words)
{
	free_them;
	exit(EXIT_SUCCESS);
}

/**
 *free_them - let them out
 *@words: These are the words of our people
 *@commands: These are the commands of our people
 *Return: none
 */
void free_them(char *words, char *command)
{
	free(words);
	free(command);
}
