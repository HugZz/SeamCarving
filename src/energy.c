/*
 * src/energy.c
 *
 * Function to compute the energy of each pixel of an image.
 *
 * author: Hugues de Valon
 * mail: hugues.devalon@gmail.com
 * date: 29/07/2016
 */

#include <stdint.h>
#include <stdlib.h>
#include <math.h>

#include "allocating.h"
#include "error.h"

/*
 * Returns the calculated horizontal gradient of the image.
 * The energy array is allocated and need to be freeed.
 * Returns NULL on error.
 */
uint8_t **gradienty(uint8_t **img, uint32_t nl, uint32_t nc)
{
	uint8_t **energy;
	uint32_t i, j;
	/*
	 * Pixel differences:
	 * - positive diagonal /
	 * - negative diagonal \
	 * - horizontal difference --
	 */
	uint32_t p_diag;
	uint32_t n_diag;
	uint32_t hor;

	if (img == NULL) {
		ERROR("given image is NULL\n");
		return NULL;
	}
	if ((energy = (uint8_t **) alloc_image(nl, nc, CHAR)) == NULL) {
		ERROR("allocation of energy array failed.\n");
		return NULL;
	}
	for (i = 0; i < nl; i++)
		for(j = 0; j < nc; j++) {
			/*
			 * We use modulo, considering the image "circular",
			 * to avoid corner cases.
			 */
			n_diag = img[(i - 1 + nl) % nl][(j - 1 + nc) % nc]
				- img[(i - 1 + nl) % nl][(j + 1) % nc];
			p_diag = img[i][(j - 1 + nc) % nc]
				- img[i][(j + 1) % nc];
			hor = img[(i + 1) % nl][(j - 1 + nc) % nc]
				- img[(i + 1) % nl][(j + 1) % nc];
			energy[i][j] = abs(p_diag + n_diag + hor) / 3.0;
		}

	return energy;
}
