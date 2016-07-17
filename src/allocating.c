#include <stdio.h>
#include <stdlib.h>
#include "../headers/projet.h"

unsigned char** alloue_image_char(int nl, int nc)
{
	int i=0;
	unsigned char** image_char = NULL;
	image_char = calloc(nl, sizeof(*image_char));
	if (image_char == NULL) 
	{
		printf("Erreur d'allocation");
		return NULL;
	}
	*image_char = calloc(nl*nc, sizeof(**image_char));
	if (*image_char == NULL) 
	{
		printf("Erreur d'allocation");
		free(image_char);
		return NULL;
	}
	for (i=1;i<nl;i++) image_char[i]=image_char[i-1]+nc;
	return image_char;
}

unsigned int** alloue_image_int(int nl, int nc)
{
	int i=0;
	unsigned int** image_int = NULL;
	image_int = calloc(nl, sizeof(*image_int));
	if (image_int == NULL) 
	{
		printf("Erreur d'allocation");
		return NULL;
	}
	*image_int = calloc(nl*nc, sizeof(**image_int));
	if (*image_int == NULL) 
	{
		printf("Erreur d'allocation");	
		free(image_int);
		return NULL;
	}
	for (i=1;i<nl;i++) image_int[i]=image_int[i-1]+nc;
	return image_int;
}

void libere_image_char(unsigned char** im)
{
	free(*im);
	free(im);
}

void libere_image_int(unsigned int** im)
{
	free(*im);
	free(im);
}
