#include "hell.h"

/**
 * printenv - prints the current environment
 * 
 */
void printenv(void)
{
	unsigned int i = 0;

	while (environ[i])
	{
		_puts(environ[i]);
		_putchar('\n');
		i++;
	}
}
