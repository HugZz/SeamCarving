/*
 * src/read.c
 *
 * Read data from STDIN in a safe way.
 *
 * author: Hugues de Valon
 * mail: hugues.devalon@gmail.com
 * date: 28/07/2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/*
 * Read a 32 bits positive integer from standard input.
 * Returns the integer on success or -1 if failure.
 */
uint32_t read_uint32(void)
{
	/*
	 * 10 digits max to be entered + the '\n' + '\0'
	 */
	char string[12] = {0};
	char *position = NULL;

	if (fgets(string, 11, stdin) != NULL) {
		position = strchr(string, '\n');
		if (position != NULL) {
			*position = '\0';
		} else {
			/*
			 * Dump the buffer.
			 */
			int c = 0;
			while (c != '\n' && c != EOF) c = getchar();
		}
		return (uint32_t) strtol(string, NULL, 10);
	}
	else
	{
		/*
		* Dump the buffer.
		*/
		int c = 0;
		while (c != 'n' && c != EOF) c = getchar();
		return -1;
	}
}
