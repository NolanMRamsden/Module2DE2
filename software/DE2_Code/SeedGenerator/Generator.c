/*
 * Generator.c
 *
 *  Created on: Nov 3, 2014
 *      Author: Karen
 */

#include "Generator.h"
#include <stdlib.h>

void generateUserKeys(SongSeed *songSeed, int numUsers)
{
	info("Generator","Creating user Keys");
	int i=0;
	for( i = 0; i < numGesturesPerSong; i++)
		songSeed->userKey[i] = rand()%numUsers+1;
	info("Generator","Done Creating user Keys");
}

void generateActionKeys(SongSeed *songSeed, int maxGestures)
{
	info("Generator","Creating action Keys");
	int i=0;
	for( i = 0; i < numGesturesPerSong; i++)
		songSeed->actionKey[i] = rand()%maxGestures+1;
	info("Generator","Done Creating action Keys");
}

void generateSongSeed(SongSeed *songSeed, int numUsers, int maxGestures)
{
	infoInt("Generator", "Creating SongSeed keys with rand seed: ",songSeed->randSeed);
	srand(songSeed->randSeed);
	generateUserKeys(songSeed,numUsers);
	generateActionKeys(songSeed,maxGestures);
}

void getUniqueUserKey(SongSeed *songSeed, int userIndex)
{
	infoInt("Generator","Getting unique array for index: ", userIndex);
	int i=0;
	for( i = 0; i < numGesturesPerSong; i++)
		if (songSeed->userKey[i] == userIndex)
			songSeed->passer[i] = songSeed->actionKey[i];
		else
			songSeed->passer[i] = 0;
}
