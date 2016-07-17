#include <stdio.h>
#include <stdlib.h>
#include "../headers/projet.h"

void calcul_cout(unsigned char** energie, unsigned int** pere,unsigned int* cout_final, int nl, int nc)
{
	
	if (pere == NULL) pere=alloue_image_int(nl, nc);
	
	unsigned int** cout = alloue_image_int(nl,nc);
	if (cout_final == NULL) printf("Erreur d'allocation.\n");
	int i = 0, j = 0, k = 0;
	
	
	for (i=0;i<nl;i++) for (j=0;j<nc;j++) cout[i][j] = 0xFFFFFFFF;
	for (j=0;j<nc;j++) cout[0][j] = energie[0][j];
	

	for (i=1;i<nl;i++) 
	{
		for (j=0;j<nc;j++)
		{
			for (k=-1;k<2;k++)
			{
				if (j+k >= 0 && j+k < nc && cout[i][j] > (cout[i-1][j+k] + energie[i][j]))
				{
					cout[i][j] = (cout[i-1][j+k] + energie[i][j]);
					pere[i][j] = j+k;
				}
			}
		}
	}
	for (j=0;j<nc;j++) cout_final[j] = cout[nl-1][j];  
	//printf("Tableau cout :\n");
	//afficheTabInt(cout,nl,nc);	
	libere_image_int(cout);
	
}
