#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "allocating.h"

unsigned char **gradienty(unsigned char **energ,unsigned char** im, int nl, int nc)
{
	if (energ == NULL) energ=(unsigned char **)alloc_image(nl,nc, CHAR);
	int i = 0;
	int j = 0;
	for (i=0;i<nl;i++) for(j=0;j<nc;j++) energ[i][j]=abs(im[(i-1+nl)%nl][(j-1+nc)%nc]-im[(i-1+nl)%nl][(j+1)%nc]+im[i][(j-1+nc)%nc]-im[i][(j+1)%nc]+im[(i+1)%nl][(j-1+nc)%nc]-im[(i+1)%nl][(j+1)%nc])/3;
	return energ;
}
