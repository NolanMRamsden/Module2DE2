/*
 * Messages.c
 *
 *  Created on: Nov 6, 2014
 *      Author: Karen
 */
#include "Messages.h"

void sendPlayerAck(Player player)
{
	Message *message = malloc(sizeof(Message));
	char data[maxNameLength+2];
	int i;
	for(i=0;i<maxNameLength;i++)
	{
		if(player.name[i] == '\0')
			data[i]=' ';
		else
			data[i]=player.name[i];
	}
	data[maxNameLength]=(int)player.clientID;
	data[maxNameLength+1]=(int)player.isHost;
	data[maxNameLength+2]='\0';

	loadData(message,data,playerAck,player.clientID);
	sendMessage(*message);

	free(message);
}

void sendNewPlayerBroadcast(Player player)
{
	Message *message = malloc(sizeof(Message));

	char data[maxNameLength+3];
	int i;
	for(i=0;i<maxNameLength;i++)
	{
		if(player.name[i] == '\0')
			data[i]=' ';
		else
			data[i]=player.name[i];
	}
	data[maxNameLength]=(int)player.inLobby;
	data[maxNameLength+1]=(int)player.clientID;
	data[maxNameLength+2]='\0';
	loadData(message,data,newPlayer,broadcast);
	sendMessage(*message);

	free(message);
}

void sendNewPlayerMessage(Player player, int clientID)
{
	Message *message = malloc(sizeof(Message));

	char data[maxNameLength+3];
	int i;
	for(i=0;i<maxNameLength;i++)
	{
		if(player.name[i] == '\0')
			data[i]=' ';
		else
			data[i]=player.name[i];
	}
	data[maxNameLength]=(int)player.inLobby;
	data[maxNameLength+1]=(int)player.clientID;
	data[maxNameLength+2]='\0';
	loadData(message,data,newPlayer,clientID);
	sendMessage(*message);
}

void sendGameOverBroadcast(Player player)
{
	Message *message = malloc(sizeof(Message));

	char data[maxNameLength+2];
	int i;
	for(i=0;i<maxNameLength;i++)
	{
		if(player.name[i] == '\0')
			data[i]=' ';
		else
			data[i]=player.name[i];
	}
	data[maxNameLength]=(int)player.clientID;
	data[maxNameLength+1]='\0';

	loadData(message,data,gameOver,broadcast);
	sendMessage(*message);

	free(message);
}

void sendGameStartArray(SongSeed *seed)
{
	Message *message = malloc(sizeof(Message));
	char data[numGesturesPerSong*2+1];
	int i;
	for(i=0;i<numGesturesPerSong;i++)
		data[2*i]  = seed->actionKey[i];

	for(i=0;i<numGesturesPerSong;i++)
		data[2*i+1]  = seed->userKey[i];

	data[numGesturesPerSong*2]='\0';
	loadData(message,data,gameArray,broadcast);
	sendMessage(*message);

	free(message);
}

void sendGameStartBroadcast(Message *message)
{
	loadData(message,message->data,gameStart,broadcast);
	sendMessage(*message);
	int i,j;
	for(i=0;i<45000;i++)
		for(j=0;j<70;j++)
		{
			int k=0;
		}
	for(i=0;i<45000;i++)
			for(j=0;j<70;j++)
			{
				int k=0;
			}
	for(i=0;i<45000;i++)
			for(j=0;j<70;j++)
			{
				int k=0;
			}
	loadData(message,message->data,gameRealStart,broadcast);
	sendMessage(*message);
}

void sendPingResponse(int clientID)
{
	Message *message = malloc(sizeof(Message));
	loadData(message,"0",0,clientID);
	free(message);
}

void broadcastMessage(Message *message)
{
	loadData(message,message->data,broadcastMe,broadcast);
	sendMessage(*message);
}
