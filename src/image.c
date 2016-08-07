/*
 * src/image.c
 *
 * Image handling functions. Easy access to BMP images.
 * Uses QDBMP library.
 *
 * author: Hugues de Valon
 * mail: hugues.devalon@gmail.com
 * date: 02/08/2016
 */

#include <stdlib.h>
#include <stdint.h>

#include "error.h"
#include "qdbmp.h"
#include "image.h"

/*
 * Our global BMP handler of the current image.
 */
static BMP *current_image;

/*
 * Open the BMP image given as filename and complete the global variable
 * current_image. Write nl and nc given as parameter.
 * Image should be initialized before calling this function.
 * Allocate current_image BMP struct which need to be freeed.
 * Returns 0 on success or a negative value on failure.
 */
int32_t open_image(char *filename, uint32_t *nl, uint32_t *nc)
{
	current_image = NULL;
	if (nl == NULL || nc == NULL) {
		ERROR("null parameters given (%p, %p)\n", nl, nc);
		return -1;
	}
	if ((current_image = BMP_ReadFile(filename)) == NULL) {
		switch(BMP_GetError()) {
		case BMP_INVALID_ARGUMENT:
			ERROR("filename is NULL\n");
			return -2;
		case BMP_OUT_OF_MEMORY:
			ERROR("no more heap memory\n");
			return -3;
		case BMP_FILE_NOT_FOUND:
			return FILE_NOT_FOUND;
		case BMP_FILE_INVALID:
			return FILE_INVALID;
		case BMP_FILE_NOT_SUPPORTED:
			return FILE_NOT_SUPPORTED;
		default:
			ERROR("error occured, can't determine reason\n");
			return -4;
		}
	}
	*nl = BMP_GetHeight(current_image);
	*nc = BMP_GetWidth(current_image);

	return 0;
}

/*
 * Fills a pre-allocated double dimension array with the greyscaled pixels of
 * the current opened image.
 * Returns 0 on success or a negative value on failure.
 */
int32_t fill(uint8_t **image, uint32_t nl, uint32_t nc)
{
	uint8_t r, g, b, grayscale;

	if (image == NULL) {
		ERROR("image not allocaed\n");
		return -1;
	}
	if (current_image == NULL) {
		ERROR("file not opened\n");
		return -1;
	}
	for (int i = 0; i < nl; i++)
		for (int j = 0; j < nc; j++) {
			BMP_GetPixelRGB(current_image, j, i, &r, &g, &b);
			if (BMP_GetError() != BMP_OK) {
				ERROR("error getting pixel (%d, %d) info\n",
						i, j);
				BMP_CHECK_ERROR(stdout, 0)
				return -1;
			}
			grayscale = (uint8_t) (r * R_WEIGHT + g * G_WEIGHT +
					b * B_WEIGHT);
			image[i][j] = grayscale;
		}

	return 0;
}

/*
 * Create the BMP file filling the pixels with the image array given.
 * Returns 0 on success and a negative value on failure.
 */
int32_t create_image(char *new_filename, uint8_t **image,
		uint32_t nl, uint32_t nc)
{
	BMP *new_image;

	if (new_filename == NULL) {
		ERROR("no filename given\n");
		return -1;
	}
	if (image == NULL) {
		ERROR("image not allocated\n");
		return -1;
	}
	if ((new_image = BMP_Create(nc, nl, 24)) == NULL) {
		ERROR("error creating new BMP struct\n");
		return -1;
	}
	for (uint32_t i = 0; i < nl; i++)
		for (uint32_t j = 0; j < nc; j++) {
			BMP_SetPixelRGB(new_image, j, i, image[i][j],
					image[i][j], image[i][j]);
			if (BMP_GetError() != BMP_OK) {
				ERROR("error writing pixel (%d, %d)\n",
						i, j);
				BMP_CHECK_ERROR(stdout, 0)
				BMP_Free(new_image);
				return -1;
			}
		}
	BMP_WriteFile(new_image, new_filename);
	if (BMP_GetError() != BMP_OK) {
		ERROR("error writing file %s\n", new_filename);
		BMP_CHECK_ERROR(stdout, 0)
		BMP_Free(new_image);
		return -1;
	}
	BMP_Free(new_image);

	return 0;
}

/*
 * Free the BMP struct of the current image.
 */
void free_bmp()
{
	BMP_Free(current_image);
	current_image = NULL;
}
