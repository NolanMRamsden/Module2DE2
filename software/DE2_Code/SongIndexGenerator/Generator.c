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
	int i=0;
	for( i = 0; i < numGesturesPerSong; i++)
		songSeed->userKey[i] = rand()%numUsers+1;
}

void generateActionKeys(SongSeed *songSeed, int maxGestures)
{
	int i=0;
	for( i = 0; i < numGesturesPerSong; i++)
		songSeed->actionKey[i] = rand()%maxGestures+1;
}

void generateSongSeed(SongSeed *songSeed, int numUsers, int maxGestures)
{
	srand(songSeed->randSeed);
	generateUserKeys(songSeed,numUsers);
	generateActionKeys(songSeed,maxGestures);
}

void getUniqueUserKey(SongSeed *songSeed, int userIndex)
{
	int i=0;
	for( i = 0; i < numGesturesPerSong; i++)
		if (songSeed->userKey[i] == userIndex)
			songSeed->passer[i] = songSeed->actionKey[i];
		else
			songSeed->passer[i] = 0;

}
