#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdint.h>

#include "../src/allocating.h"

/*
 * Tests the allocating function.
 */
void test_allocating_basic(void **state)
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

/*
 * Tests memory corruption.
 */
void test_allocating_mem_corrupt(void **state)
{
	uint32_t **image = (uint32_t **)alloc_image(10, 20, INT);
	assert_non_null(image);
	/*
	 * Writing in a case should leave the other cases intact.
	 */
	image[5][10] = 42;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 20; j++) {
			if (i == 5 && j == 10) {
				continue;
			}
			assert_int_equal(image[i][j], 0);
		}
	free_image((void **)image);
	assert_non_null(image);

	/*
	 * Allocating two arrays one after the other.
	 * They should have different memory: writing in one should not write
	 * in the other.
	 */
	uint32_t **image1 = (uint32_t **)alloc_image(10, 20, INT);
	uint32_t **image2 = (uint32_t **)alloc_image(10, 20, INT);
	image1[0][0] = 0xDEADBEEF;
	image1[0][19] = 0xDEADBEEF;
	image1[9][0] = 0xDEADBEEF;
	image1[9][19] = 0xDEADBEEF;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 20; j++)
			assert_int_equal(image2[i][j], 0);
	free_image((void **)image1);
	free_image((void **)image2);

	/*
	 * Reverse than above.
	 */
	uint32_t **image11 = (uint32_t **)alloc_image(10, 20, INT);
	uint32_t **image22 = (uint32_t **)alloc_image(10, 20, INT);
	image22[0][0] = 0xDEADBEEF;
	image22[0][19] = 0xDEADBEEF;
	image22[9][0] = 0xDEADBEEF;
	image22[9][19] = 0xDEADBEEF;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 20; j++)
			assert_int_equal(image11[i][j], 0);
}

