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

#define INFO 3
#define WARN 2
#define ERR  1
#define OFF  0

#ifndef LOGGER_H_
#define LOGGER_H_

extern void setLogLevel(int level);
extern void info(char *tag, char *message);
extern void infoInt(char *tag, char *message, int num);
extern void warn(char *tag, char *message);
extern void error(char *tag, char *message);
extern void displayArray(int *array);
extern void printArray(SongSeed *songSeed, int index);

#endif /* LOGGER_H_ */
