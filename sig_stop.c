#include "hell.h"
/**
 *sig_stop - stoooooopp
 *@sNum: its a number
 *Return: nuthin
 */
void sig_stop(int sNum)
{
	char *sigMsg = "\nYou shell not pass!";

	(void)sNum;
	write(STDOUT_FILENO, sigMsg, strlen(sigMsg));
	write(STDOUT_FILENO, "\n$ ", 3);
}
