/*
 * Logger.h
 *
 *  Created on: Nov 3, 2014
 *      Author: Karen
 */
#include "../includes.h"

#define PASSER  1
#define USERKEY 2
#define ACTIONKEY 3

#ifndef LOGGER_H_
#define LOGGER_H_

extern void setLogLevel(int level);
extern void info(char *tag, char *message);
extern void warn(char *tag, char *message);
extern void error(char *tag, char *message);
extern void printArray(SongSeed *songSeed, int index);

#endif /* LOGGER_H_ */
