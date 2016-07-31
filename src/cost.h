/*
 * src/cost.h
 *
 * Calcule the cost of each possible path (from top to bottom) of the image.
 *
 * author: Hugues de Valon
 * mail: hugues.devalon@gmail.com
 * date: 31/07/2016
 */

/*
 * Fills final_cost with the total cost of the nc lowest expensive paths of
 * the image.
 * Fills father_column with, for each pixel, the column number that yield to
 * a minimal cost.
 * Returns 0 on success, negative value on failure.
 */
int32_t cost(uint32_t **father_column, uint32_t *final_cost,
		uint8_t **energy, uint32_t nl, uint32_t nc);
