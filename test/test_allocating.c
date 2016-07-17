#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdint.h>

#include "../src/allocating.h"

/*
 * Tests the allocating function.
 */
void test_allocating(void **state)
{
	uint32_t **image = (uint32_t **)alloc_image(6, 3, INT);
	assert_non_null(image);
	for (int i = 0; i < 6; i++)
		assert_non_null(image[i]);
	/*
	 * After the allocating, the array should be filled with zeroes.
	 */
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 3; j++)
			assert_null(image[i][j]);
	/*
	 * Write in each case of the array should not make a segmentation fault.
	 */
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 3; j++)
			image[i][j] = i + j;

	free_image((void **)image);
	assert_non_null(image);
}
