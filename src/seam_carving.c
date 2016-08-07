/*
 * src/seam_carving.c
 *
 * Main file for seam carving function.
 *
 * author: Hugues de Valon
 * mail: hugues.devalon@gmail.com
 * date: 31/07/2016
 */

#include <stdlib.h>
#include <stdint.h>

#include "energy.h"
#include "allocating.h"
#include "cost.h"
#include "find_path.h"
#include "delete_column.h"
#include "error.h"

/*
 * This function returns image with columns_to_delete columns deleted.
 * The returned array is allocated and need to be freeed by user.
 * Far right deleted pixels are remplaced with zeroes.
 * Returns NULL on error.
 */
uint8_t **seam_carving(uint8_t **image, uint32_t columns_to_delete,
		uint32_t nl, uint32_t nc)
{
	uint8_t **new_image, **energy;
	uint32_t **father_column;
	uint32_t *final_cost, *best_path;
	uint32_t i, j, k;

	if ((new_image = (uint8_t **) alloc_image(nl, nc, CHAR)) == NULL) {
		ERROR("allocation new_image failed.\n");
		return NULL;
	}
	for (i = 0; i < nl; i++)
		for (j = 0; j < nc; j++)
			new_image[i][j] = image[i][j];
	for (k = 0; k < columns_to_delete; k++)
	{
		energy = gradienty(new_image, nl, nc);
		if (energy == NULL) {
			ERROR("calculating energy failed.\n");
			free_image((void **) new_image);
			return NULL;
		}
		father_column = (uint32_t **) alloc_image(nl, nc, INT);
		if (father_column == NULL) {
			ERROR("calculating energy failed.\n");
			free_image((void **) new_image);
			free_image((void **) energy);
			return NULL;
		}
		final_cost = calloc(nc, sizeof(uint32_t));
		if (final_cost == NULL) {
			perror("Allocation of final_cost failed.");
			free_image((void **) father_column);
			free_image((void **) new_image);
			free_image((void **) energy);
			return NULL;
		}
		if (cost(father_column, final_cost, energy, nl, nc) < 0) {
			ERROR("failed calculating cost.\n");
			free(final_cost);
			free_image((void **) father_column);
			free_image((void **) new_image);
			free_image((void **) energy);
			return NULL;
		}
		best_path = calloc(nl, sizeof(unsigned int));
		if (best_path == NULL) {
			perror("Allocation of best_path failed.");
			free(final_cost);
			free_image((void **) father_column);
			free_image((void **) new_image);
			free_image((void **) energy);
			return NULL;
		}
		if (optimal_path(best_path, father_column, final_cost, nl, nc)
				< 0) {
			ERROR("failed finding the optimal path.\n");
			free(final_cost);
			free(best_path);
			free_image((void **) father_column);
			free_image((void **) new_image);
			free_image((void **) energy);
			return NULL;
		}
		if (delete_column(new_image, best_path, nl,nc) < 0) {
			ERROR("failed deleting columns.\n");
			free(final_cost);
			free(best_path);
			free_image((void **) father_column);
			free_image((void **) new_image);
			free_image((void **) energy);
			return NULL;
		}
		nc--;
	}
	free(final_cost);
	free(best_path);
	free_image((void **) father_column);
	free_image((void **) energy);

	return new_image;
}
