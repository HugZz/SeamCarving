#include <stdio.h>
#include <stdlib.h>
#include "../headers/projet.h"


unsigned char** zoomx(unsigned char** im, int nbcol, int nl, int nc)
{
	int i,j;
	double nj;
	double k = (double)(nc - nbcol)/(double)nc;
	//printf("k vaut %lf\n", k);
	unsigned char** zmx = NULL;
	zmx = alloue_image_char(nl, nc-nbcol);
	for (i=0;i<nl;i++) 
	{
		for(j=0;j<(nc-nbcol);j++)
		{
			nj=(1/k)*(j-nc/2)+nc/2;
			zmx[i][j]=im[i][(int)(nj+0.5)];
		}
	}
	return zmx;
}
