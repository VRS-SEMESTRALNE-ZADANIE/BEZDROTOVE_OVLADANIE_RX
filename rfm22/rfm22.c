/*
 * rfm22.c
 *
 *  Created on: Dec 16, 2024
 *      Author: mihal
 */
#include "rfm22.h"

void rfm22_rx_init(void)
{

    // Disable interrupts
    spi_write(0x06, 0x00);

    // Set device to READY mode
    spi_write(0x07, 0x01);

    // Set frequency to 434 MHz
    spi_write(0x75, 0x53);
    spi_write(0x76, 0x64);
    spi_write(0x77, 0x00);

    // Set FIFO mode for RX
    spi_write(0x71, 0x20);

    // Set packet length
    spi_write(0x3E, 1);

    // Set synchronization word
    spi_write(0x36, 0x2D);
    spi_write(0x37, 0xD4);

    // Enable CRC, Packet RX Handling
    spi_write(0x30, 0x04);

    //  spi_write(0x6E, 0x27); // Data Rate, vyšší bajt
    //  spi_write(0x6F, 0x52); // Data Rate, nižší bajt

    spi_write(0x6E, 0x27); // Data Rate, vyšší bajt
    spi_write(0x6F, 0x52); // Data Rate, nižší bajt
    spi_write(0x70, 0x20); // Modulácia: FSK, FIFO režim
    spi_write(0x34, 0x14); // Preamble Length
    spi_write(0x35, 0x14); // Preamble Detection Length
    spi_write(0x3F, 0x00); // Header Control
    spi_write(0x27, 0x20); // RSSI treshhold
    spi_write(0x09, 0x7f); //crystal
    //clear TX RX
    spi_write(0x08, 0x03);
    spi_write(0x08, 0x00);
}

void rfm22_receive(uint8_t *buffer, uint8_t length)
{
	 spi_write(0x08, 0x03);
	 spi_write(0x08, 0x00);

    uint8_t reg3, reg4;
    reg3 = spi_read(0x03); // Čítanie Interrupt Status 1
    reg4 = spi_read(0x04); // Čítani

	uint8_t RSSI1_sila, RSSI2_trh,type;

	RSSI1_sila = spi_read(0x26); // Čítanie Interrupt Status 1
	RSSI2_trh = spi_read(0x27);
    // Set device to RX mode
    spi_write(0x07, 0x05);
          //for (int i = 0; i < 1; i++) {
       	  //	buffer[i]=spi_read(0x7F); // Prečítanie bajtov z RX FIFO
       	  // }
    buffer=spi_read(0x7F);

	reg3 = spi_read(0x03); // Čítanie Interrupt Status 1
	reg4 = spi_read(0x04); // Čítani
	type = spi_read(0x00);

    // Read data from RX FIFO

    // Wait for TXDONE flag (TX completed)

    // Return to READY mode after reception
    spi_write(0x07, 0x01);
}


