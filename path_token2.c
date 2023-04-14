#include "hell.h"
/**
 * *_strchr - points to first instance of c in s
 * @s: input string
 * @c: char to be located
 * Return: point to first instance or NULL if none
 */
char *_strchr(const char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return ((char *) s);
		}
		s++;
	}
	if (c == '\0')
	{
		return ((char *) s);
	}
	return (NULL);
}
/**
 * *_strcat - meows 2 strings together
 * @dest: where big string goes and other smol string comes
 * @src: smol string input
 * Return: big string
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	while (dest[i])
	{
		i++;
	}
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * *_strcpy - function for to copy chararr
 * @src: source of chararr
 * @dest: destination of chararr
 * Return: finaldestination
 */
char *_strcpy(char *dest, char *src)
{
	int a = 0;

	while (*(src + a))
	{
		*(dest + a) = *(src + a);
		a++;
	}
	dest[a] = '\0';
	return (dest);
}
