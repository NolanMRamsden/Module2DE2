/*
 * Communication.c
 *
 *  Created on: Nov 5, 2014
 *      Author: Karen
 */


#include "Communication.h"

void recieveData(Message *message)
{
	int i;
	int bytes_expected;
	int bytes_recvd;
	int total_recvd;
	unsigned char data;
	unsigned char message_rx[100];

	bytes_expected = 1;
	total_recvd = 0;
	while (total_recvd < bytes_expected) {
		bytes_recvd = usb_device_recv(&data, 1);
		if (bytes_recvd > 0)
			total_recvd += bytes_recvd;
	}
	message->clientID=(int)data;

	bytes_expected = 1;
	total_recvd = 0;
	while (total_recvd < bytes_expected) {
		bytes_recvd = usb_device_recv(&data, 1);
		if (bytes_recvd > 0)
			total_recvd += bytes_recvd;
	}
	message->numLength=(int)data;

	bytes_expected = 1;
	total_recvd = 0;
	while (total_recvd < bytes_expected) {
		bytes_recvd = usb_device_recv(&data, 1);
		if (bytes_recvd > 0)
			total_recvd += bytes_recvd;
	}
	message->type = data;

	bytes_expected = message->numLength - 1;
	total_recvd = 0;
	while (total_recvd < bytes_expected) {
		bytes_recvd = usb_device_recv(message_rx + total_recvd, 1);
		if (bytes_recvd > 0)
			total_recvd += bytes_recvd;
	}
	message->length=message->numLength;
	message->fullMessage[0]=message->type;
	for(i=0;i<98;i++)
	{
		message->data[i]=message_rx[i];
		message->fullMessage[i+1]=message_rx[i];
	}

	if(message->length > 1)
	{
		int l = 0;
	}

	return;
}

void sendMessage(Message message)
{
	usb_device_send(&message.fullMessage, message.numLength+2);
	int i,j;
	for(i=0;i<65000;i++)
		for(j=0;j<70;j++)
		{
			int k=0;
		}
}

void loadData(Message *message, char *data, char type, unsigned int clientID)
{
	message->clientID=clientID;
	message->numLength=strlen(data)+2;
	message->length=strlen(data)+2;
	message->type=(int)type;

	int i;
	message->fullMessage[0]=clientID;
	message->fullMessage[1]=message->length;
	message->fullMessage[2]=message->type;
	for(i=0;i<100;i++)
	{
		if(i<strlen(data))
		{
			message->fullMessage[i+3]=data[i];
			message->data[i]=data[i];
		}else if(i<97)
		{
			message->fullMessage[i+3]='\0';
			message->data[i]='\0';
		}else
		{
			message->data[i]='\0';
		}
	}
}
