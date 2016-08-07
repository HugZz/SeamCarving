/*
 * src/cost.c
 *
 * Calculate the cost of each possible path (from top to bottom) of the image.
 *
 * author: Hugues de Valon
 * mail: hugues.devalon@gmail.com
 * date: 31/07/2016
 */

#include <stdlib.h>

#include "allocating.h"
#include "error.h"

/*
 * Fills final_cost with the total cost of the nc lowest expensive paths of
 * the image.
 * Fills father_column with, for each pixel, the column number that yield to
 * a minimal cost.
 * Returns 0 on success, negative value on failure.
 */
int32_t cost(uint32_t **father_column, uint32_t *final_cost,
		uint8_t **energy, uint32_t nl, uint32_t nc)
{
	uint32_t **cost;
	/*
	 * Cost of the whole path to go to this pixel from the first line.
	 */
	uint32_t path_cost;
	uint32_t i, j;
	/*
	 * Father column offset: only -1, 0 or 1.
	 */
	int8_t k;

	if (father_column == NULL) {
		ERROR("father_column array not allocated\n");
		return -1;
	}
	if (energy == NULL) {
		ERROR("energy array not allocated\n");
		return -1;
	}
	if (final_cost == NULL) {
		ERROR("final_cost array not allocated\n");
		return -1;
	}
	if ((cost = (uint32_t **) alloc_image(nl, nc, INT)) == NULL) {
		ERROR("allocating cost array failed\n");
		return -2;
	}
	/*
	 * Each pixel initialized with maximal cost.
	 */
	for (i = 0; i < nl; i++)
		for (j = 0; j < nc; j++)
			cost[i][j] = 0xFFFFFFFF;
	/*
	 * We start from first line.
	 */
	for (j = 0; j < nc; j++)
		cost[0][j] = energy[0][j];

	for (i = 1; i < nl; i++)
		for (j = 0; j < nc; j++)
			for (k= -1; k < 2; k++) {
				if (j + k >= 0 && j + k < nc)
					path_cost = cost[i - 1][j + k] +
						energy[i][j];
				else
					continue;
				if (cost[i][j] > path_cost)
				{
					/*
					 * We found a path with a lower cost.
					 * Use it.
					 */
					cost[i][j] = path_cost;
					father_column[i][j] = j + k;
				}
			}
	for (j = 0; j < nc; j++)
		final_cost[j] = cost[nl - 1][j];
	free_image((void **) cost);

	return 0;
}
