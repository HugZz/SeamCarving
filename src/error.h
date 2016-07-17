/*
 * src/error.h
 *
 * Error handling macros.
 *
 * author: Hugues de Valon
 * mail: hugues.devalon@gmail.com
 * date: 16/07/2016
 */

#ifndef __ERROR__
#define __ERROR__

#include <stdlib.h>

#define ERROR(...)							\
	do {								\
		printf("ERROR: %s:%s\t", __FILE__, __LINE__);		\
		printf(__VA_ARGS__);					\
	} while (0)

#endif /* __ERROR__ */
