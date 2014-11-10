/*
 * Generator.h
 *
 *  Created on: Nov 3, 2014
 *      Author: Karen
 */

#define numGesturesPerSong  20
#define maxNumGestures       4

#include "../Lobby/Lobby.h"

#ifndef GENERATOR_H_
#define GENERATOR_H_


typedef struct SongSeed
{
	int randSeed;
	int userKey[numGesturesPerSong];
	int actionKey[numGesturesPerSong];
	int passer[numGesturesPerSong];
} SongSeed;

extern void generateUserKeys(SongSeed *songSeed, LobbyRoom *lobby);
extern void generateActionKeys(SongSeed *songSeed, int maxGestures);
extern void generateSongSeed(SongSeed *songSeed, LobbyRoom *lobby, int maxGestures);
extern void getUniqueUserKey(SongSeed *songSeed, int clientID);

#endif /* GENERATOR_H_ */
