
#define NULL       ((void*)0)

#include "usb/usb.h"
#include "altera_up_avalon_usb.h"
#include "system.h"
#include "sys/alt_timestamp.h"
#include "io.h"
#include "includes.h"

alt_up_usb_dev * usb_dev;


void getBoardConnection()
{
	usb_dev = alt_up_usb_open_dev(USB_0_NAME);
	usb_device_init(usb_dev, USB_0_IRQ);

	while (getSwitchIndex() != 1) {
		usb_device_poll();
	}
}

void run(LobbyRoom *lobby, Message *trigger, SongSeed *seed)
{
	generateSongSeed(seed, lobby, 5);
	sendGameStartArray(seed);
	sendGameStartBroadcast(trigger);
}

void sendArrays(LobbyRoom *lobby, Message *trigger, SongSeed *seed)
{
	generateSongSeed(seed, lobby, 5);
	sendGameStartArray(seed);
}

int main()
{
	int j;

	usb_dev = malloc(sizeof(alt_up_usb_dev));
	SongSeed *seed = malloc(sizeof(SongSeed));
	Message *inMessage = malloc(sizeof(Message));
	LobbyRoom *lobby = malloc(sizeof(LobbyRoom));
	Player *tempPlayer = malloc(sizeof(Player));
	initRoom(lobby);
	getBoardConnection();
	seed->randSeed = 1341;
	while(1)
	{
		recieveData(inMessage);
		switch(inMessage->type)
		{
			case gameLost:
				sendGameOverBroadcast(inMessage->clientID);
				break;
			case playerLeave:
				removePlayerFromLobby(lobby, inMessage->clientID);
				break;
			case levelOver:
				lobby->level++;
				run(lobby,inMessage,seed);
				break;
			case newPlayer:
				loadPlayer(tempPlayer,inMessage);
				if(getClientIDIndex(lobby,inMessage->clientID) == -1)
					addPlayerToLobby(lobby, *tempPlayer);
				else
					sendPlayerAck(lobby->players[getClientIDIndex(lobby,inMessage->clientID)]);
				break;
			case startGame:
				run(lobby,inMessage,seed);
				break;
			case broadcastMe:
				broadcastMessage(inMessage);
				break;
			case moreArrays:
				sendArrays(lobby,inMessage,seed);
				break;
			default:
				sendPingResponse(inMessage->clientID);
				break;
		}
		if(lobby->playerCount == 0)
		{
			lobby->inPlay=0;
			lobby->hasHost=0;
		}
	}

	return 0;
}



