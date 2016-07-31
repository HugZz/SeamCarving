/*
 * src/delete_column.c
 *
 * Deletes the best_path of the image and translates all the pixels to the left.
 * The last right column is filled with zeroes.
 *
 * author: Hugues de Valon
 * mail: hugues.devalon@gmail.com
 * date: 31/07/2016
 */

#include <stdint.h>
#include <stdlib.h>

#include "error.h"

/*
 * Returns a negative value on error or 0 on success.
 */
int32_t delete_column(uint8_t **image, uint32_t *best_path,
		uint32_t nl, uint32_t nc)
{
	uint32_t i, j;

	if (image == NULL) {
		ERROR("image array not allocated\n");
		return -1;
	}
	if (best_path == NULL) {
		ERROR("best_path array not allocated\n");
		return -1;
	}

	for (i = 0; i < nl; i++) {
		for (j = best_path[i]; j < nc - 1; j++)
			image[i][j] = image[i][j + 1];
		image[i][nc - 1] = 0;
	}

	return 0;
}
