/*
 * src/pretty_print.h
 *
 * Functions to pretty print arrays.
 *
 * author: Hugues de Valon
 * mail: hugues.devalon@gmail.com
 * date: 28/07/2016
 */

#ifndef __PRETTY_PRINT__
#define __PRETTY_PRINT__

#include <stdint.h>

/*
 * Print an array in a good way depending of its type.
 * Returns 0 on succes, -1 if tab is NULL, -2 if wrong size.
 */
int32_t pretty_print(void **tab, uint32_t lines, uint32_t columns, size_t type);

#endif /* __PRETTY_PRINT__ */
