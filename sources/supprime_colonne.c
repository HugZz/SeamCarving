#include <stdio.h>
#include <stdlib.h>
#include "../headers/projet.h"

void supprime_colonne(unsigned char** im, unsigned int* ch_max,int nl, int* pnc) 
{
	int i = 0, j = 0;
	for (i=0;i<nl;i++) 
	{	
		for (j=ch_max[i];j++;j<(*pnc)-1)//Même comment par rapport à l'ordre dans le for
		{
			im[i][j]=im[i][j+1];
		}
		im[i][(*pnc)-1]=0;
	}
	(*pnc)--;

}

