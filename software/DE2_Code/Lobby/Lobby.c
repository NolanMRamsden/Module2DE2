/*
 * Lobby.c
 *
 *  Created on: Nov 4, 2014
 *      Author: Karen
 */

#include "Lobby.h"

void initRoom(LobbyRoom *room)
{
	room->hasHost=0;
	room->inPlay=0;
	room->level=0;
	room->playerCount=0;
	room->startStamp=0;
	int i;
	for(i=0;i<maxPlayers;i++)
	{
		room->players[i].inLobby=2;
		room->players[i].isHost=2;
		room->players[i].clientID=0;
	}
}

void loadPlayer(Player *player, Message *inMessage)
{
	int i;
	for(i=0;i<maxNameLength;i++)
		player->name[i]=inMessage->data[i];
	player->clientID=inMessage->clientID;
}

void addPlayerToLobby(LobbyRoom *room, Player player)
{
	int i;
	for(i=0;i<maxNameLength;i++)
		room->players[room->playerCount].name[i]=player.name[i];
	room->players[room->playerCount].clientID=player.clientID;
	room->players[room->playerCount].inLobby=1;
	if(room->hasHost==0)
	{
		room->players[room->playerCount].isHost=1;
		room->hasHost=1;
	}else
	{
		room->players[room->playerCount].isHost=2;
	}
	sendNewPlayerBroadcast(room->players[room->playerCount]);
	sendPlayerAck(room->players[room->playerCount]);
	for(i=0;i<room->playerCount;i++)
	{
		sendNewPlayerMessage(room->players[i],player.clientID);
	}
	room->playerCount++;
}

void removePlayerFromLobby(LobbyRoom *room, int clientID)
{
	room->playerCount--;
	int i,j, wasHost;
	int index = getClientIDIndex(room,clientID);
	room->players[index].inLobby=2;
	wasHost=room->players[index].isHost;
	sendNewPlayerBroadcast(room->players[index]);
	for(i=index; i < maxPlayers; i++)
	{
		for(j=0;j<maxNameLength;j++)
				room->players[i].name[j]=room->players[i+1].name[j];
		room->players[i].clientID=room->players[i+1].clientID;
		room->players[i].inLobby=room->players[i+1].inLobby;
		room->players[i].isHost=room->players[i+1].isHost;
	}
	if(wasHost == 1 && room->playerCount > 0)
	{
		room->players[0].isHost=1;
		sendPlayerAck(room->players[0]);
	}else if(wasHost ==1 && room->playerCount == 0)
	{
		room->hasHost=0;
	}
}

int getClientIDIndex(LobbyRoom *room, int clientID)
{
	int i;
	int index = -1;
	for( i=0; i<maxPlayers; i++)
	{
		if(clientID==room->players[i].clientID && room->players[i].inLobby)
			index=i;
	}
	return index;
}
