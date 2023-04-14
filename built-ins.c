#include "hell.h"
/**
 * _strlen - function to find length of string
 * @s: string input
 * Return: string length
 */
int _strlen(const char *s)
{
	int a = 0;

	while (*(s + a) != '\0')
	{
		a++;
	}
	return (a);
}

/**
 * _strncmp - compares strings up to n chars
 * @s1: first string
 * @s2: second string
 * @n: num of chars to compare
 * Return: first dif or 0 if none
 */
int _strncmp(char *s1, char *s2, int n)
{
	int i = 0, dif = 0;

	while (s1[i] && s2[i] && (i < n))
	{
		if (s1[i] == s2[i])
		{
			i++;
			continue;
		}
		else
		{
			dif = s1[i] - s2[i];
			break;
		}
	}
	return (dif);
}

/**
 * _strcmp - compares strings ASCII values
 * @s1: first string
 * @s2: second string
 * Return: first dif
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0, dif = 0;

	while (s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
		{
			i++;
			continue;
		}
		else
		{
			dif = s1[i] - s2[i];
			break;
		}
	}
	return (dif);
}
