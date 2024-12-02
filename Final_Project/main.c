/*
 * @file main.c
 *
 * @brief Main source code for the UART program.
 *
 * This file contains the main entry point and function definitions for the UART program.
 *
 * @note For more information regarding the UART module, refer to the
 * Universal Asynchronous Receivers / Transmitters (UARTs) section
 * of the TM4C123GH6PM Microcontroller Datasheet.
 *   - Link: https://www.ti.com/lit/gpn/TM4C123GH6PM
 *
 * @author
 */

#include "TM4C123GH6PM.h"
#include "UART.h"
#include "SysTick_Delay.h"
#include "GPIO.h"
#include "Buzzer.h"
#include "SWORD.h"

int main(void)
{
	const double notes[7] = 
	{
		C4_NOTE,
		D4_NOTE,
		E4_NOTE,
		F4_NOTE,
		G4_NOTE,
		A4_NOTE,
		B4_NOTE
	};
//Initialize the SysTick Timer used to provide a blocking delay function
	SysTick_Delay_Init();
		
	//Initialize the LEDs on the EduBase board (Port B)
	EduBase_LEDs_Init();
		
	//Initialize the button (Sw2 -Sw5) on the EduBase board (Port D)
	EduBase_Button_Init();
	
	RGB_LED_Init();
	
		
	//Initialize the DMT-1206 Magnetic Buzzer (Port C)
	Buzzer_Init();
	UART0_Init();
	UART0_Output_Newline();
	CreateUser();
	UART0_Output_String("S.W.O.R.D Initialized");
	while(1)
	{
		UART0_Output_Newline();
		DisplayMenu();
	}
}