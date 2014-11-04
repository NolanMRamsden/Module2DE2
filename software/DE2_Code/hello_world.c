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

#include "usb/usb.h"
#include "altera_up_avalon_usb.h"
#include "system.h"
#include "sys/alt_timestamp.h"
#include "includes.h"

#include <assert.h>
#include <stdio.h>

int ConnectCode() {
	/*
	int i;
	int bytes_expected;
	int bytes_recvd;
	int total_recvd;
	unsigned char data;
	unsigned char message_tx[] = "EECE381 is so much fun";
	unsigned char message_rx[100];

	info("usb testing","USB Initialization");
	alt_up_usb_dev * usb_dev;
	usb_dev = alt_up_usb_open_dev(USB_0_NAME);
	assert(usb_dev);
	usb_device_init(usb_dev, USB_0_IRQ);

	info("usb testing","Polling USB device.  Run middleman now!");
	alt_timestamp_start();
	int clocks = 0;
	while (clocks < 50000000 * 10) {
		clocks = alt_timestamp();
		usb_device_poll();
	}
	info("usb testing","Done polling USB");

	info("usb testing","Sending the message to the Middleman");

	// Start with the number of bytes in our message
	unsigned char message_length = strlen(message_tx);
	usb_device_send(&message_length, 1);

	// Now send the actual message to the Middleman
	usb_device_send(message_tx, message_length);

	// Now receive the message from the Middleman
	info("usb testing","Waiting for data to come back from the Middleman");

	// First byte is the number of characters in our message
	bytes_expected = 1;
	total_recvd = 0;
	while (total_recvd < bytes_expected) {
		bytes_recvd = usb_device_recv(&data, 1);
		if (bytes_recvd > 0)
			total_recvd += bytes_recvd;
	}

	int num_to_receive = (int) data;
	info("usb testing","About to receive characters:");

	bytes_expected = num_to_receive;
	total_recvd = 0;
	while (total_recvd < bytes_expected) {
		bytes_recvd = usb_device_recv(message_rx + total_recvd, 1);
		if (bytes_recvd > 0)
			total_recvd += bytes_recvd;
	}

	for (i = 0; i < num_to_receive; i++) {
		info("usb testing", message_rx[i]);
	}
	info("usb testing","Message Echo Complete");
	*/
	return 0;
}


int main()
{

	initVGA();
	SongSeed *seed = malloc(sizeof(SongSeed));
	seed->randSeed=19;
	generateSongSeed(seed,4,7);
	info("arrayTest","test test");
	printArray(seed,ACTIONKEY);
	printArray(seed,USERKEY);
	warn("another","test");

	/*
	alt_up_usb_dev * usbDev;
	usbDev = alt_up_usb_open_dev(USB_0_NAME);
	assert(usbDev);

	usb_device_init(usbDev, USB_0_IRQ);

	info("usb testing","Polling usb device");

	while(1)
	{
		usb_device_poll();
	}*/

	return 0;
}



