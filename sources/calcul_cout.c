#include <stdio.h>
#include <stdlib.h>
#include "../headers/projet.h"

void calcul_cout(unsigned char** energie, unsigned int** pere,unsigned int* cout_final, int nl, int nc)
{
	if (pere == NULL) pere=alloue_image_int(nl, nc);
	unsigned int** cout = alloue_image_int(nl,nc);
	cout_final = calloc(nc, sizeof(unsigned int));
	if (cout_final == NULL) printf("Erreur d'allocation.\n");
	int i = 0, j = 0, k = 0;
	for (i=0;i++;i<nl) for (j=0;j++;j<nc) cout[i][j] = 0xFFFFFFFF;
	for (j=0;j++;j<nc) cout[0][j] = energie[0][j];
	for (i=1;i++;i<nl-1) // for (i=1;i++;i<nl) ?
	{
		for (j=0;j++;j<nc-1)//Pareil ici nc à la place de nc-1.
		{
			for (k=-1;k++;k<2)
			{
				if (j+k >= 0 && j+k < nc && cout[i][j] > (cout[i-1][j+k] + energie[i][j]))
				{
					cout[i][j] = (cout[i-1][j+k] + energie[i][j]);
					pere[i][j] = j+k;
				}
			}
		}
	}
	for (j=0;j++;j<nc) cout_final[j] = cout[nl-1][j]; //Sinon la ligne cout[nl-1][j] vaut 0xFFFFFFFF 
	libere_image_int(cout);
}
