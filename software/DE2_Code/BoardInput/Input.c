/*
 * Input.c
 *
 *  Created on: Nov 4, 2014
 *      Author: Karen
 */
#define switches   (volatile char*)   0x00004030

#include "Input.h"

int getSwitchIndex()
{
	int i=0;
	for(i=0;i<8;i++)
	{
		if( ((IORD_8DIRECT(switches,0) >> i) & 1) == 1)
			return i;
	}
	return -1;
}
