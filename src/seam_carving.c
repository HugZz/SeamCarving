#include <stdio.h>
#include <stdlib.h>

#include "project.h"
#include "energy.h"
#include "allocating.h"
#include "cost.h"

unsigned char** seam_carving(unsigned char** im, int nbcol, int nl, int nc)
{
	unsigned char** ims = NULL;
	ims = (unsigned char **)alloc_image(nl,nc, CHAR);

	int i=0;
	int j=0;
	int ncb = nc;
	for (i=0;i<nl;i++) for (j=0;j<nc;j++) ims[i][j]=im[i][j];

	for (j=0;j<nbcol;j++)
	{

		unsigned char** energie = NULL; //energie de l'image
		energie = gradienty(ims,nl,ncb);
		//printf("\nEnergie de l'image :\n");
		//afficheTab(energie,nl,ncb);

		unsigned int** pere = NULL; //indication pour chaque case du numéro de colonne par laquelle on est arrivé
		pere=(unsigned int **)alloc_image(nl,ncb, INT); //allouer le tableau à l'intérieur de la fonction calcul_cout donnait des problèmes
		unsigned int* cout_final = NULL; //indication du cout du chemin pour arriver à la derniere case
		cout_final = calloc(nc, sizeof(unsigned int)); //idem
		cost(pere,cout_final, energie, nl,ncb);
		//printf("Tableau père :\n");
		//printf("Tableau cout_final : \n");
		//affiche1D(cout_final,ncb);

		unsigned int* ch_max = NULL; //numéro de la colonne pour le chemin correspondant à chaque ligne
		ch_max = calloc(nl, sizeof(unsigned int));
		int k=0; //numéro de colonne de la dernière case du chemin
		k++;
		k = trouve_chemin(ch_max,pere,cout_final,nl,ncb);
		//printf("k = %d\n", k);
		//printf("Tableau du chemin :\n");
		//affiche1D(ch_max,nl);
		supprime_colonne(ims,ch_max,nl,&ncb);

	}
	return ims;
}
