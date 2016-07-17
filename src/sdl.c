#include <stdio.h>
#include <stdlib.h>
#include "project.h"
#include "allocating.h"

/*
 * Return the pixel value at (x, y)
 * NOTE: The surface must be locked before calling this!
 */
Uint32 getpixel(SDL_Surface *surface, int x, int y)
{
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to retrieve */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp) {
    case 1:
        return *p;

    case 2:
        return *(Uint16 *)p;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
            return p[0] << 16 | p[1] << 8 | p[2];
        else
            return p[0] | p[1] << 8 | p[2] << 16;

    case 4:
        return *(Uint32 *)p;

    default:
        return 0;       /* shouldn't happen, but avoids warnings */
    }
}

/*
 * Set the pixel at (x, y) to the given value
 * NOTE: The surface must be locked before calling this!
 */
void putpixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to set */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp) {
    case 1:
        *p = pixel;
        break;

    case 2:
        *(Uint16 *)p = pixel;
        break;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
            p[0] = (pixel >> 16) & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = pixel & 0xff;
        } else {
            p[0] = pixel & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = (pixel >> 16) & 0xff;
        }
        break;

    case 4:
        *(Uint32 *)p = pixel;
        break;
    }
}

unsigned char **lire_image(char* image,int* nl, int* nc)
{
	Uint8 r,g,b;
	int i,j;
	SDL_Surface* img = NULL;
	img = SDL_LoadBMP(image);
	*nl=img->h;
	*nc=img->w;
	unsigned char **im = NULL;
	im = (unsigned char **)alloc_image(*nl,*nc, CHAR);
	for (i=0;i<*nl;i++)
	{
		for (j=0;j<*nc;j++)
		{
			SDL_GetRGB(getpixel(img,j,i), img->format, &r, &g, &b);
			im[i][j]=(unsigned char)r;
		}
	}
	SDL_FreeSurface(img);
	return im;
}

void dessiner(unsigned char** im,SDL_Surface *screen, SDL_Surface *img, SDL_Rect pos, int nl, int nc)
{
	int i,j;
	SDL_FillRect(img, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
	Uint32 pixel;
	for (i=0;i<nl;i++)
	{
		for (j=0;j<nc;j++)
		{
			pixel = SDL_MapRGB(img->format, (Uint8) im[i][j], (Uint8) im[i][j], (Uint8) im[i][j]);
			putpixel(img,j,i,pixel);
		}
	}
	SDL_BlitSurface(img, NULL, screen, &pos);
}

