/*
 * Generator.c
 *
 *  Created on: Nov 3, 2014
 *      Author: Karen
 */

#include "Generator.h"
#include <stdlib.h>

void generateUserKeys(SongSeed *songSeed, LobbyRoom *lobby)
{
	int keys[lobby->playerCount];
	int i=0;
	for( i = 0; i < lobby->playerCount; i++)
		keys[i]=lobby->players[i].clientID;
	for( i = 0; i < numGesturesPerSong; i++)
		songSeed->userKey[i] = keys[rand()%lobby->playerCount];
}

void generateActionKeys(SongSeed *songSeed, int maxGestures)
{
	int i=0;
	for( i = 0; i < numGesturesPerSong; i++)
		songSeed->actionKey[i] = rand()%maxGestures+1;
}

void generateSongSeed(SongSeed *songSeed, LobbyRoom *lobby, int maxGestures)
{
	srand(songSeed->randSeed);
	songSeed->randSeed++;
	generateUserKeys(songSeed,lobby);
	generateActionKeys(songSeed,maxGestures);
}

void getUniqueUserKey(SongSeed *songSeed, int clientID)
{
	int i=0;
	for( i = 0; i < numGesturesPerSong; i++)
		if (songSeed->userKey[i] == clientID)
			songSeed->passer[i] = songSeed->actionKey[i];
		else
			songSeed->passer[i] = 0;
}
