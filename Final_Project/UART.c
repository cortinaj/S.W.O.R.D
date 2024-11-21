/**
 * @file UART0.c
 *
 * @brief Source code for the UART0 driver.
 *
 * This file contains the function definitions for the UART0 driver.
 *
 */


#include "UART.h"


void UART0_Init(void)
{
	//Enable the clock to the UART0 module by setting the
	//R0 bit (Bit 0) in the RCGCUART register
	SYSCTL -> RCGCUART |= 0x01;
	
	//Enable the clock to Port A by setting the
	// R0 bit (Bit 0) in the RCGCGPIO register
	SYSCTL -> RCGCGPIO |= 0x01;
	
	//Disable the UART0 module before configuration by clearing
	//the UARTEN bit (Bit 0) in the CTL register
	UART0 -> CTL &= ~0x0001;
	
	//Configure the UART0 module to use the system clock (50MHz)
	//divided by 16 by clearing the HSE bit (Bit 5) in the CTL register
	UART0 -> CTL &= ~0x0020;
	
	//Set the baud rate by writing to the DIVINT field (Bits 15 to 0)
	//and the DIVFRAC field (Bits 5 to 0) in the IBRD and FBRD regsiters, respectively.
	//The integer part of the calculated constant will be written to the IBRD regster,
	//while the fractional part will be written to the FBRD regsiter.
	//BRD = (System clock Frequency) / (16 * Baud Rate)
	//BRDI = (50,000,000) / (16 * 115200) = 27.12673611 (IBRD = 27)
	//BRDF = ((0.12673611 * 64) + 0.5) = 8.611 (FBRD = 8)
	UART0 -> IBRD = 27;
	UART0 -> FBRD = 8;
	
	//Config data length of the UART packet to be 8 bits by writing a
	//value of 0x3 to the WLEN field (Bits 6 to 5) in the LCRH register
	UART0 -> LCRH |= 0x60;
	
	//Enable the Transmit FIFO and the Receive FIFO by setting the FEN bit
	//(Bit 4) in the LCRH regsiter
	UART0 -> LCRH |= 0x10;
	
	//Select one stop by to be transmitted at the end of a UART frame by clearing
	//the STP2 bit (Bit 3) in the LCRH register.
	UART0 -> LCRH &= ~0x08;
	
	//Disable the parity bit by clearing the PEN bit (Bit 1) in the LCRH register
	UART0 -> LCRH &= ~0x02;
	
	//Enable the UART0 module after config by setting the UARTEN bit (bit 0) in
	//The CTL register.
	UART0 -> CTL |= 0x01;
	
	//Select AFSEL for PA1 and PA0 pins by setting Bits 0 and 1 in the AFSEL register
	//The pins will be configured as Tx and Rx pins respectively.
	GPIOA -> AFSEL |= 0x03;
	
	//Clear the PMC1 (Bits 7 to 4) and PMC0 (Bits 3 to 0) fields in the PCTL register
	//for Port A before config
	GPIOA -> PCTL &= ~0x000000FF;
	
	//Config PA1 pin to operate as a U0Tx pin by writing 0x1 to the PMC1 field
	//(Bits 7 to 4) in the PCTL register
	GPIOA -> PCTL |= 0x00000010;
	
	//Config PA0 pin to operate as a U0RX pin by writing 0x1 to the PMC0 field
	//(Bits 3 to 0) in the PCTL regsiter
	GPIOA -> PCTL |= 0x00000001;
	
	//Enable the DEN functionality for the PA1 and PA0 pins by setting Bits 1 to 0
	//in the DEN register
	GPIOA -> DEN |= 0x03;
}

char UART0_Input_Character(void)
{
	while ((UART0 -> FR & UART0_RECEIVE_FIFO_EMPTY_BIT_MASK) != 0);

	return (char) (UART0 -> DR & 0xFF);
}

void UART0_Output_Character(char data)
{
	while((UART0 -> FR & UART0_TRANSMIT_FIFO_FULL_BIT_MASK) != 0);
	
	UART0 -> DR = data;
}

void UART0_Input_String(char *buffer_pointer, uint16_t buffer_size)
{
	int length = 0;
	char character = UART0_Input_Character();
	
	while(character != UART0_CR)
	{
		if (character == UART0_BS)
		{
			if(length)
			{
				buffer_pointer--;
				length--;
				UART0_Output_Character(UART0_BS);
			}
		}
		else if(length < buffer_size)
		{
			*buffer_pointer = character;
			buffer_pointer++;
			length++;
			UART0_Output_Character(character);
		}
		character = UART0_Input_Character();
	}
	*buffer_pointer = 0;
}

void UART0_Output_String(char *pt)
{
	while (*pt)
	{
		UART0_Output_Character(*pt);
		pt++;
	}
}


void UART0_Output_Newline(void)
{
	UART0_Output_Character(UART0_CR);
	UART0_Output_Character(UART0_LF);
}

	