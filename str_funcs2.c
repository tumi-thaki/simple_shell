#include "shell.h"

char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);

/**
 * _strchr - locates a character in a string
 * @s: string to be searched
 * @c: character to be located
 *
 * Return: a pointer to the first occurence of c, NULL otherwise
*/

char *_strchr(char *s, char c)
{
	int index;

	for (index = 0; s[index]; index++)
	{
		if (s[index] == c)
			return (s + index);
	}

	return (NULL);
}

/**
 * _strspn - gets the length of a prefix substring
 * @s: string to be searched
 * @accept: prefix to be measured
 *
 * Return: the number of bytes in s which
 *         match the bytes from accept
*/

int _strspn(char *s, char *accept)
{
	int bytes = 0;
	int index;

	while (*s)
	{
		for (index = 0; accept[index]; index++)
		{
			if (*s == accept[index])
			{
				bytes++;
				break;
			}
		}
		s++;
	}

	return (bytes);
}

/**
 * _strcmp - compares two strings
 * @s1: first string to be compared
 * @s2: second string to be compared
 *
 * Return: positive byte difference if s1 > s2
 *         0 if s1 = s2
 *         negative byte difference if s1 < s2
*/

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);

	return (0);
}

/**
 * _strncmp - compares two strings
 * @s1: first string to be compared
 * @s2: second string to be compared
 * @n: first n bytes of the strings to compare
 *
 * Return: negative byte difference if s1 is shorter than s2
 *         0 if s1 and s2 match
 *         positive byte difference if s1 is longer than s2
*/

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; s1[i] && s2[i] && i < n; i++)
	{
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
	}

	if (i == n)
		return (0);
	else
		return (-15);
}
