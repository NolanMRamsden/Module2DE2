/*
 * VGA.c
 *
 *  Created on: Nov 3, 2014
 *      Author: Karen
 */
#include "VGA.h"

static alt_up_pixel_buffer_dma_dev* pixel_buffer;
static alt_up_char_buffer_dev *char_buffer;

void initVGA()
{
	pixel_buffer = malloc(sizeof(alt_up_pixel_buffer_dma_dev));
		char_buffer  = malloc(sizeof(alt_up_char_buffer_dev));
		// Use the name of your pixel buffer DMA core
		pixel_buffer = alt_up_pixel_buffer_dma_open_dev("/dev/video_pixel_buffer_dma_0");

		unsigned int pixel_buffer_addr1 = PIXEL_BUFFER_BASE;

		// Set the background buffer address ?Although we don’t use the
		//background,
		// they only provide a function to change the background
		// buffer address, so
		// we must set that, and then swap it to the foreground.
		alt_up_pixel_buffer_dma_change_back_buffer_address(pixel_buffer, pixel_buffer_addr1);
		// Swap background and foreground buffers
		alt_up_pixel_buffer_dma_swap_buffers(pixel_buffer);
		// Wait for the swap to complete
		while (alt_up_pixel_buffer_dma_check_swap_buffers_status(pixel_buffer));

		// Initialize character buffer
		char_buffer = alt_up_char_buffer_open_dev("/dev/video_character_buffer_with_dma_0");
		alt_up_char_buffer_init(char_buffer);

		clearScreen();
}

void clearScreen()
{
	alt_up_char_buffer_clear(char_buffer);
	alt_up_pixel_buffer_dma_clear_screen(pixel_buffer, 0);
}

void clearCharacters()
{
	alt_up_char_buffer_clear(char_buffer);
}

void drawText(char *text, int x, int y)
{
	alt_up_char_buffer_string(char_buffer,text,x,y);
}
