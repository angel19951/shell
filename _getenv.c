#include "shell.h"

/**
 * _getenv - finds and prints the enviroment variable of the PATH
 * @name: variable PATH to look for
 * Return: NULL on fail || enviroment variable
 */

char *_getenv(const char *name)
{
	extern char **environ;
	char **envPtr;
	char *charPtr;
	const char *nHolder;


	for (envPtr = environ; *envPtr != NULL; envPtr++)
	{
		for (charPtr = *envPtr, nHolder = name; *charPtr == *nHolder; charPtr++, nHolder++)
		{
			if (*charPtr == '=')
			{
				break;
			}
		}
		if ((*charPtr == '=') && (*nHolder == '\0'))
		{
			return (charPtr + 1);
		}
	}
	return (NULL);
}
