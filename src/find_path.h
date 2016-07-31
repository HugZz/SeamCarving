/*
 * src/find_path.h
 *
 * Calculate the optimal path with the lowest cost.
 *
 * author: Hugues de Valon
 * mail: hugues.devalon@gmail.com
 * date: 31/07/2016
 */

#ifndef __FIND_PATH__
#define __FIND_PATH__

/*
 * Fills best_path array with the path (coord: (i, best_path[i])) with the
 * lowest cost.
 * Returns the last column number of this path or a negative value on error.
 */
int32_t optimal_path(uint32_t *best_path, uint32_t **father_column,
		uint32_t *final_cost, uint32_t nl, uint32_t nc);

#endif /* __FIND_PATH__ */
