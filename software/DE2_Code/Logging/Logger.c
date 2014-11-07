/*
 * Logger.c
 *
 *  Created on: Nov 3, 2014
 *      Author: Karen
 */

#define NULL       ((void*)0)
#include "Logger.h"

int logCount = 1;
int logDepth = 3;

void setLogLevel(int level)
{
	if(level == 0)
		clearCharacters();
	else
		infoInt("Logger","Log depth set to: ",level);

	logDepth = level;
}

void log(char *type, char *tag, char *message)
{
	char str[80];
	strcpy(str, type);
	strcat(str, " -- ");
	strcat(str, tag);
	strcat(str, " :  ");
	strcat(str, message);
	drawText(str,0,logCount);
	drawText("                                                                    |",0,logCount+1);
	drawText("                                                                    |",0,logCount+2);
	drawText("                                                                    |",0,logCount+3);
	logCount++;
	if(logCount >= 59)
	{
		logCount=1;
	}
	free(str);
}

void printArray(SongSeed *songSeed, int index)
{
	if(index == USERKEY)
	{
		info("PrintArray", "user Keys");
		displayArray(songSeed->userKey);
	}
	else if(index == ACTIONKEY)
	{
		info("PrintArray", "action Keys");
		displayArray(songSeed->actionKey);

	}else if(index == PASSER)
	{
		info("PrintArray", "passer Keys");
		displayArray(songSeed->passer);
	}
	logCount+=2;
}

void displayArray(int *array)
{
	int i=0;
	char str[80];
	char helper[10];
	strcpy(str,"");
	for(i=0; i< numGesturesPerSong; i++)
	{
		strcat(str,"[");
		sprintf(helper,"%d",i);
		strcat(str,helper);
		strcat(str,"]" );
	}
	drawText(str,0,++logCount);
	strcpy(str,"");
	for(i=0; i< numGesturesPerSong; i++)
	{
		if(i<10)
			strcat(str," ");
		else
			strcat(str,"  ");
		sprintf(helper,"%d",array[i]);
		strcat(str,helper);
		strcat(str," " );
	}
	drawText(str,0,++logCount);
	free(str);
	free(helper);
}

void info(char *tag, char *message) {if(logDepth < 3) return; log("[INFO] ",tag,message);}
void infoInt(char *tag, char *message, int num)
{
	if(logDepth < 3) return;
	char str[10];
	sprintf(str,"%d",num);
	strcat(message,str);
	log("[INFO] ",tag,message);
	free(str);
}
void warn(char *tag, char *message) {if(logDepth < 2) return; log("[WARN] ",tag,message);}
void error(char *tag, char *message){if(logDepth < 1) return; log("[ERROR]",tag,message);}


