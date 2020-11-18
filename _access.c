#include "shell.h"
#include "_string.h"
#include "string1.c"
#include "string2.c"
#include "getenv.c"

/**
 * main - looks for a comman in all directories of PATH
 * @ac: ammount of attributes passed to main
 * @argv: arguments passed to main
 * Return: 1 if success || -1 if fail
 */
int main(__attribute__((unused))int ac, char *argv[])
{
	struct stat st;
	char *check = NULL;
	char *path = _getenv("PATH");
	char **tokens = _strtok(path, ":");

	while (*tokens != NULL)
	{
		check = concatenator(3, *tokens, "/", argv[1]);
		if (stat(check, &st) == 0)
		{
			printf("FOUND in %s\n", check);
			free(check);
			exit(0);
		}
		else
		{
			printf("Not found in %s\n", check);
		}
		tokens++;
		if (check)
			free(check);
	}
	return (0);
}
