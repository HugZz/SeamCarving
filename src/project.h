#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL/SDL.h>

unsigned int** alloue_image_int(int nl, int nc);
unsigned char** alloue_image_char(int nl, int nc);
void libere_image_char(unsigned char** im);
void libere_image_int(unsigned int** im);
unsigned char** zoomx_image(unsigned char **ims, unsigned char **im, int nbcol, int jc, int nl, int nc); 
void calcul_cout(unsigned char** energie, unsigned int** pere, unsigned int* coutfinal,int nl, int nc); 
int trouve_chemin(unsigned int* ch_max, unsigned int** pere, unsigned int* coutfinal, int nl, int nc);
void supprime_colonne(unsigned char** im, unsigned int* ch_max,int nl, int* pnc); 
unsigned char** seam_carving(unsigned char** im, int nbcol, int nl, int nc);
unsigned char** gradienty(unsigned char** energ,unsigned char** im, int nl, int nc);
int lire();
void afficheTab(unsigned char **tab,int nl, int nc);
void afficheTabInt(unsigned int **tab,int nl, int nc);
Uint32 getpixel(SDL_Surface *surface, int x, int y);
void putpixel(SDL_Surface *surface, int x, int y, Uint32 pixel);
void dessiner(unsigned char** im,SDL_Surface *screen, SDL_Surface *img, SDL_Rect pos, int nl, int nc);
unsigned char **lire_image(char* image,int* nl, int* nc);
