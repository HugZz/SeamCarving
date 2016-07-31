/*
 * src/seam_carving.h
 *
 * Main file for seam carving function.
 *
 * author: Hugues de Valon
 * mail: hugues.devalon@gmail.com
 * date: 31/07/2016
 */

#ifndef __SEAM_CARVING__
#define __SEAM_CARVING__

/*
 * This function returns image with columns_to_delete columns deleted.
 * Far right deleted pixels are remplaced with zeroes.
 * Returns NULL on error.
 */
uint8_t **seam_carving(uint8_t **image, uint32_t columns_to_delete,
		uint32_t nl, uint32_t nc);

#endif /* __SEAM_CARVING__ */
