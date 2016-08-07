/*
 * src/image.h
 *
 * Image handling functions. Easy access to BMP images.
 * Uses QDBMP library.
 *
 * author: Hugues de Valon
 * mail: hugues.devalon@gmail.com
 * date: 02/08/2016
 */

#ifndef __IMAGE__
#define __IMAGE__

/*
 * Error codes
 */
#define FILE_NOT_FOUND		0xDEADBEEF
#define FILE_INVALID		0xDEADB00B
#define FILE_NOT_SUPPORTED	0xBEEFDEAD
#define WRONG_WIDTH		0xDEADDEAD

/*
 * RGB weights
 */
#define R_WEIGHT		0.2989
#define G_WEIGHT		0.5870
#define B_WEIGHT		0.1140

/*
 * Open the BMP image given as filename and complete the global variables
 * current_image, nl and nc.
 * Image should be initialized before calling this function.
 * Allocate current_image BMP struct which need to be freeed.
 * Returns 0 on success or a negative value on failure.
 */
int32_t open_image(char *filename, uint32_t *nl, uint32_t *nc);

/*
 * Fills a pre-allocated double dimension array with the greyscaled pixels of
 * the current opened image.
 * Returns 0 on success or a negative value on failure.
 */
int32_t fill(uint8_t **image, uint32_t nl, uint32_t nc);

/*
 * Create the BMP file filling the pixels with the image array given.
 * Returns 0 on success and a negative value on failure.
 */
int32_t create_image(char *new_filename, uint8_t **image,
		uint32_t nl, uint32_t nc);

/*
 * Free the BMP struct of the current image.
 */
void free_bmp();

#endif /* __IMAGE__ */
