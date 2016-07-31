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
#include <stdio.h>

#define ERROR(...)							\
	do {								\
		fprintf(stderr, "ERROR: %s:%d\t\t", __FILE__, __LINE__);\
		fprintf(stderr, __VA_ARGS__);				\
	} while (0)

#endif /* __ERROR__ */
