/*
 * src/main.c
 *
 * Main function. Where it all begins and where it all ends.
 *
 * author: Hugues de Valon
 * mail: hugues.devalon@gmail.com
 * date: 31/07/2016
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "image.h"
#include "error.h"
#include "allocating.h"
#include "seam_carving.h"
#include "pretty_print.h"

/*
 * Check for the correctness of given arguments and call the high-level
 * functions.
 * Returns to the OS EXIT_SUCCESS or EXIT_FAILURE (if he ever uses it).
 */
int main(int argc, char *argv[])
{
	uint32_t new_width, return_value;
	uint32_t nl, nc;
	char *filename, *destination;
	uint8_t **image;
	uint8_t **result_image;

	if (argc != 4) {
		printf("usage: ./seamcarving IMAGE_NAME NEW_WIDTH DESTINATION\n");
		return EXIT_FAILURE;
	}
	new_width = (uint32_t) atol(argv[2]);
	filename = argv[1];
	destination = argv[3];
	return_value = open_image(filename, &nl, &nc);
	if (return_value != 0)
		switch (return_value) {
		case FILE_NOT_FOUND:
			printf("error: can't find file \'%s\'\n", filename);
			return EXIT_FAILURE;
		case FILE_NOT_SUPPORTED:
			printf("error: file \'%s\'\n not supported\n",
					filename);
			return EXIT_FAILURE;
		case FILE_INVALID:
			printf("error: invalid file \'%s\'\n", filename);
			return EXIT_FAILURE;
		default:
			ERROR("error opening file \'%s\'\n", filename);
			return EXIT_FAILURE;
		}
	if (new_width == nc) {
		printf("%d is the width of the given image, nothing to do\n",
				new_width);
		free_bmp();
		return EXIT_SUCCESS;
	}
	if (new_width > nc) {
		printf("error: wanted width %d is bigger than original image\n",
				new_width);
		free_bmp();
		return EXIT_FAILURE;
	}
	if ((image = (uint8_t **) alloc_image(nl, nc, CHAR)) == NULL) {
		ERROR("allocating image failed\n");
		free_bmp();
		return EXIT_FAILURE;
	}
	if (fill(image, nl, nc) < 0) {
		ERROR("problem filling the image\n");
		free_bmp();
		free_image((void **) image);
		return EXIT_FAILURE;
	}
	free_bmp();
	result_image = seam_carving(image, nc - new_width, nl, nc);
	if (result_image == NULL) {
		ERROR("error seam carving the image\n");
		free_image((void **) image);
		return EXIT_FAILURE;
	}
	free_image((void **) image);
	return_value = create_image(destination, result_image, nl, new_width);
	if (return_value < 0) {
		ERROR("can not create image\n");
		free_image((void **) result_image);
		return EXIT_FAILURE;
	}
	free_image((void **) result_image);

	return EXIT_SUCCESS;
}
