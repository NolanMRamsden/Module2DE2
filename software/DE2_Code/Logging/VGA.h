/*
 * VGA.h
 *
 *  Created on: Nov 3, 2014
 *      Author: Karen
 */

#ifndef VGA_H_
#define VGA_H_

#include "altera_up_avalon_video_character_buffer_with_dma.h"
#include "altera_up_avalon_video_pixel_buffer_dma.h"

extern void initVGA();
extern void clearScreen();
extern void clearCharacters();
extern void drawText(char *text, int x, int y);

#endif /* VGA_H_ */
