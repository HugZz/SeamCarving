/*
 * src/energy.h
 *
 * Function to compute the energy of each pixel of an image.
 *
 * author: Hugues de Valon
 * mail: hugues.devalon@gmail.com
 * date: 29/07/2016
 */

#ifndef __ENERGY__
#define __ENERGY__

#include <stdint.h>

/*
 * Returns the calculated horizontal gradient of the image.
 * Returns NULL on error.
 */
uint8_t **gradienty(uint8_t **image, uint32_t lines, uint32_t columns);

#endif /* __ENERGY__ */
