/*
 * src/find_path.c
 *
 * Calculate the optimal path with the lowest cost.
 *
 * author: Hugues de Valon
 * mail: hugues.devalon@gmail.com
 * date: 31/07/2016
 */

#include <stdint.h>
#include <stdlib.h>

#include "error.h"

/*
 * Fills best_path array with the path (coord: (i, best_path[i])) with the
 * lowest cost.
 * Returns the last column number of this path or a negative value on error.
 */
int32_t optimal_path(uint32_t *best_path, uint32_t **father_column,
		uint32_t *final_cost, uint32_t nl, uint32_t nc)
{
	uint32_t min_final_cost;
	uint32_t less_expensive_last_column;

	if (best_path == NULL) {
		ERROR("best_path array not allocated\n");
		return -1;
	}
	if (father_column == NULL) {
		ERROR("father_column array not allocated\n");
		return -1;
	}
	if (final_cost == NULL) {
		ERROR("final_cost array not allocated\n");
		return -1;
	}

	min_final_cost = final_cost[0];
	less_expensive_last_column = 0;
	for (uint32_t j = 1; j < nc; j++)
		if (min_final_cost > final_cost[j]) {
			min_final_cost = final_cost[j];
			less_expensive_last_column = j;
		}

	best_path[nl - 1] = less_expensive_last_column;
	/*
	 * Warning: int32_t type for i, otherwise we face integer overflow
	 * and it breaks the program.
	 */
	for (int32_t i = nl - 2; i >= 0; i--)
		best_path[i] = father_column[i + 1][best_path[i + 1]];

	return less_expensive_last_column;
}
