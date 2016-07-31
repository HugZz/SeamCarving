/*
 * src/delete_column.h
 *
 * Deletes the best_path of the image and translates all the pixels to the left.
 * The last right column is filled with zeroes.
 *
 * author: Hugues de Valon
 * mail: hugues.devalon@gmail.com
 * date: 31/07/2016
 */

#ifndef __DELETE_COLUMN__
#define __DELETE_COLUMN__

/*
 * Returns a negative value on error or 0 on success.
 */
int32_t delete_column(uint8_t **image, uint32_t *best_path,
		uint32_t nl, uint32_t nc);

#endif /* __DELETE_COLUMN__ */
