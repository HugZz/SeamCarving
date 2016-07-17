#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lire()
{
	char chaine[100] = {0};
	char* position = NULL;
	if (fgets(chaine, 100, stdin) != NULL)
	{
		position = strchr(chaine, '\n');
		if (position != NULL) *position = '\0';
		else
		{
			int c=0;
			while (c != '\n' && c != EOF) c = getchar();
		}
		return (int) strtol(chaine, NULL, 10);
	}
	else 
	{
		int c=0;
		while (c != 'n' && c != EOF) c = getchar();
		return -1;
	}


}
