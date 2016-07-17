/*
 * src/allocating.h
 *
 * This file contains functions to allocate the arrays where
 * the pictures will reside.
 *
 * author: Hugues de Valon
 * mail: hugues.devalon@gmail.com
 * date: 16/07/2016
 */

#ifndef __ALLOCATING__
#define __ALLOCATING__

/*
 * Defines to be used in alloc_image function.
 */
#define CHAR 1
#define SHORT 2
#define INT 4

void **alloc_image(int lines, int columns, size_t bytes_per_element);
void free_image(void **image);

#endif /* __ALLOCATING__ */
