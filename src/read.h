/*
 * src/read.h
 *
 * Read data from STDIN in a safe way.
 *
 * author: Hugues de Valon
 * mail: hugues.devalon@gmail.com
 * date: 28/07/2016
 */

#ifndef __READ__
#define __READ__

#include <stdint.h>

/*
 * Read a 32 bits positive integer from standard input.
 * Returns the integer on success or -1 if failure.
 */
int32_t read_uint32(void);

#endif /* __READ__ */
