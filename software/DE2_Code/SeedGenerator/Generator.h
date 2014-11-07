/*
 * Generator.h
 *
 *  Created on: Nov 3, 2014
 *      Author: Karen
 */

#define numGesturesPerSong  20
#define maxNumGestures       4

#ifndef GENERATOR_H_
#define GENERATOR_H_


typedef struct SongSeed
{
	int randSeed;
	int userKey[numGesturesPerSong];
	int actionKey[numGesturesPerSong];
	int passer[numGesturesPerSong];
} SongSeed;

extern void generateUserKeys(SongSeed *songSeed, int numUsers);
extern void generateActionKeys(SongSeed *songSeed, int maxGestures);
extern void generateSongSeed(SongSeed *songSeed, int numUsers, int maxGestures);
extern void getUniqueUserKey(SongSeed *songSeed, int userIndex);

#endif /* GENERATOR_H_ */
