/*
 * "Hello World" example.
 *
 * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
 * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example
 * designs. It runs with or without the MicroC/OS-II RTOS and requires a STDOUT
 * device in your system's hardware.
 * The memory footprint of this hosted application is ~69 kbytes by default
 * using the standard reference design.
 *
 * For a reduced footprint version of this template, and an explanation of how
 * to reduce the memory footprint for a given application, see the
 * "small_hello_world" template.
 *
 */
#define NULL       ((void*)0)

#include "usb/usb.h"
#include "altera_up_avalon_usb.h"
#include "system.h"
#include "sys/alt_timestamp.h"
#include "io.h"
#include "includes.h"

#include <assert.h>
#include <stdio.h>

alt_up_usb_dev * usb_dev;


void getBoardConnection()
{
	usb_dev = alt_up_usb_open_dev(USB_0_NAME);
	assert(usb_dev);
	usb_device_init(usb_dev, USB_0_IRQ);

	while (getSwitchIndex() != 1) {
		usb_device_poll();
	}
}

void run(LobbyRoom *lobby, Message *trigger)
{
	SongSeed *seed = malloc(sizeof(SongSeed));
	Message *inMessage = malloc(sizeof(Message));
	seed->randSeed = 14;
	generateSongSeed(seed, lobby, 3);
	sendGameStartArray(seed);
	sendGameStartBroadcast(trigger);
	lobby->inPlay=1;
	return;
	int i,j;
	while(lobby->inPlay)
	{
		//recieveData(inMessage);
		switch(inMessage->type)
		{
			case gameLost:
				j=getClientIDIndex(lobby,inMessage->clientID);
				if(j != -1)
					sendGameOverBroadcast(lobby->players[j]);
				break;
			case playerLeave:
				removePlayerFromLobby(lobby, inMessage->clientID);
				break;
			case levelOver:
				generateSongSeed(seed, lobby, 3);
				sendGameStartArray(seed);
				sendGameStartBroadcast(inMessage);
				break;
		}


	}
	free(seed);
}

int main()
{
	usb_dev = malloc(sizeof(alt_up_usb_dev));
	Message *inMessage = malloc(sizeof(Message));
	LobbyRoom *lobby = malloc(sizeof(LobbyRoom));
	Player *tempPlayer = malloc(sizeof(Player));
	initRoom(lobby);
	getBoardConnection();

	/*
	SongSeed *seed = malloc(sizeof(SongSeed));
	seed->randSeed = 14;
	loadData(inMessage,"Nolan          ",newPlayer,1);
	loadPlayer(tempPlayer,inMessage);
	addPlayerToLobby(lobby, *tempPlayer);
	loadData(inMessage,"Jaren          ",newPlayer,2);
	loadPlayer(tempPlayer,inMessage);
	addPlayerToLobby(lobby, *tempPlayer);
	loadData(inMessage,"Ethan          ",newPlayer,3);
	loadPlayer(tempPlayer,inMessage);
	addPlayerToLobby(lobby, *tempPlayer);
	generateSongSeed(seed, lobby, 3);
	sendGameStartArray(seed);*/

	return 0;

	int i=0,j=0;
	while(i<=10)
	{
		//recieveData(inMessage);
		switch(i)
		{
			case 0:
				loadData(inMessage,"Nolan          ",newPlayer,1);
				break;
			case 1:
				loadData(inMessage,"Jaren          ",newPlayer,2);
				break;
			case 2:
				loadData(inMessage,"Ethan          ",newPlayer,3);
				break;
			case 3:
				loadData(inMessage,"Mitch          ",newPlayer,4);
				break;
			case 4:
				loadData(inMessage,"Jaren          ",playerLeave,2);
				break;
			case 5:
				loadData(inMessage,"Jaren          ",gameLost,2);
				break;
			case 6:
				loadData(inMessage,"Nolan          ",gameLost,1);
				break;
			case 7:
				loadData(inMessage,"1111",startGame,1);
				break;
			case 8:
				loadData(inMessage,"2222",startGame,2);
				break;
			case 9:
				loadData(inMessage,"Nolan          ",playerLeave,1);
				break;
			case 10:
				loadData(inMessage,"1111",startGame,3);
				break;
		}
		switch(inMessage->type)
		{
			case gameLost:
				j=getClientIDIndex(lobby,inMessage->clientID);
				if(j != -1)
					sendGameOverBroadcast(lobby->players[j]);
				break;
			case newPlayer:
				loadPlayer(tempPlayer,inMessage);
				addPlayerToLobby(lobby, *tempPlayer);
				break;
			case playerLeave:
				removePlayerFromLobby(lobby, inMessage->clientID);
				break;
			case startGame:
				j = getClientIDIndex(lobby,inMessage->clientID);
				if(j != -1)
					if(lobby->players[j].isHost==1)
						run(lobby,inMessage);
				break;
		}
		i++;
	}

	return 0;
}



