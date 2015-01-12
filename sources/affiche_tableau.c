#include <stdio.h>
#include <stdlib.h>

void afficheTab(unsigned char **tab,int nl, int nc)
{
	int i,j;
	for (i=0;i<nl;i++)
	{
		printf("Ligne n°%d|", i);
		for (j=0;j<nc;j++)
		{
			printf("    %d    |",tab[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}

void afficheTabInt(unsigned int **tab,int nl, int nc)
{
	int i,j;
	for (i=0;i<nl;i++)
	{
		printf("|");
		for (j=0;j<nc;j++)
		{
			printf("    %d    |",tab[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}

void affiche1D(unsigned int* tab, int n)
{
	int i;
	printf("|");
	for (i=0;i<n;i++)
	{
		printf("      %d     |",tab[i]);
	}
	printf("\n\n");
}
