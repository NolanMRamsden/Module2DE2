/*
 * VGA.c
 *
 *  Created on: Nov 3, 2014
 *      Author: Karen
 */
#include "VGA.h"

static alt_up_char_buffer_dev *char_buffer;
static alt_up_pixel_buffer_dma_dev* pixel_buffer;

void initVGA()
{
	char_buffer  = malloc(sizeof(alt_up_char_buffer_dev));
	pixel_buffer = malloc(sizeof(alt_up_pixel_buffer_dma_dev));

	// Initialize character buffer
	char_buffer = alt_up_char_buffer_open_dev("/dev/video_character_buffer_with_dma_0");
	alt_up_char_buffer_init(char_buffer);
	// Init pixel buffer
	pixel_buffer = alt_up_pixel_buffer_dma_open_dev("/dev/video_pixel_buffer_dma_0");
	alt_up_pixel_buffer_dma_change_back_buffer_address(pixel_buffer, PIXEL_BUFFER_BASE);
	alt_up_pixel_buffer_dma_swap_buffers(pixel_buffer);

	while (alt_up_pixel_buffer_dma_check_swap_buffers_status(pixel_buffer));

	clearScreen();
	clearCharacters();
	info("VGA","VGA initialized");
}

void clearScreen()
{
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
