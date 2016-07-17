#include <stdio.h>
#include <stdlib.h>
#include "../headers/projet.h"

unsigned char** seam_carving(unsigned char** im, int nbcol, int nl, int nc)
{
	unsigned char** ims = NULL;
	ims = alloue_image_char(nl,nc);

	int i=0;
	int j=0;
	int ncb = nc;	
	for (i=0;i<nl;i++) for (j=0;j<nc;j++) ims[i][j]=im[i][j];
	
	for (j=0;j<nbcol;j++)
	{
		
		unsigned char** energie = NULL; //energie de l'image
		energie = gradienty(energie,ims,nl,ncb);
		//printf("\nEnergie de l'image :\n");
		//afficheTab(energie,nl,ncb);
			
		unsigned int** pere = NULL; //indication pour chaque case du numéro de colonne par laquelle on est arrivé
		pere=alloue_image_int(nl,ncb); //allouer le tableau à l'intérieur de la fonction calcul_cout donnait des problèmes
		unsigned int* cout_final = NULL; //indication du cout du chemin pour arriver à la derniere case
		cout_final = calloc(nc, sizeof(unsigned int)); //idem
		calcul_cout(energie,pere,cout_final,nl,ncb);
		//printf("Tableau père :\n");
		//afficheTabInt(pere,nl,ncb);
		//printf("Tableau cout_final : \n");
		//affiche1D(cout_final,ncb);

		unsigned int* ch_max = NULL; //numéro de la colonne pour le chemin correspondant à chaque ligne
		ch_max = calloc(nl, sizeof(unsigned int));
		int k=0; //numéro de colonne de la dernière case du chemin
		k = trouve_chemin(ch_max,pere,cout_final,nl,ncb);
		//printf("k = %d\n", k);
		//printf("Tableau du chemin :\n");
		//affiche1D(ch_max,nl);
		supprime_colonne(ims,ch_max,nl,&ncb);
		
	}
	return ims;
}
