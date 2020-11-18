#include "shell.h"


int main(void)
{
	char *myEnv __attribute__((unused));

	myEnv = _getenv("PATH");
	printf("PATH=%s\n", myEnv);

	myEnv = _getenv("HOME");
	printf("HOME=%s\n", myEnv);

	myEnv = _getenv("USER");
	printf("USER=%s\n", myEnv);

	myEnv = _getenv("PASSWORD");
	printf("PASSWORD=%s\n", myEnv);
	return (0);
}

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
