/*
 * src/pretty_print.c
 *
 * Functions to pretty print arrays.
 *
 * author: Hugues de Valon
 * mail: hugues.devalon@gmail.com
 * date: 28/07/2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "allocating.h"

/*
 * Print an array in a good way depending of its type.
 * Returns 0 on succes, -1 if tab is NULL, -2 if wrong size.
 */
uint32_t pretty_print(void **tab, uint32_t lines, uint32_t columns, size_t type)
{
	uint32_t i, j;

	if (tab == NULL)
		return -1;
	switch (type) {
	case CHAR:
		/*
		 * From 0 to 255: 3 digits max
		 */
		for (i = 0; i < lines; i++) {
			for (j = 0; j < columns; j++)
				printf("|%3d", ((uint8_t **) tab)[i][j]);
			printf("|\n");
		}
		break;
	case SHORT:
		/*
		 * From 0 to 65535: 5 digits max
		 */
		for (i = 0; i < lines; i++) {
			for (j = 0; j < columns; j++)
				printf("|%5d", ((uint16_t **) tab)[i][j]);
			printf("|\n");
		}
		break;
	case INT:
		/*
		 * From 0 to 4294967295: 10 digits max
		 */
		for (i = 0; i < lines; i++) {
			for (j = 0; j < columns; j++)
				printf("|%10d", ((uint8_t **) tab)[i][j]);
			printf("|\n");
		}
		break;
	default:
		return -2;
	}
	return 0;
}
