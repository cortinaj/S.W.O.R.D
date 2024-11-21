 /**
 * @file Door_Control.c
 *
 * @brief Source code for controlling door status.
 *
 * This file contains the definitions of all the functions required for checking and maintaing door status.
 *
 * @author John Paul D. Cortina
 */
  #include "Door_Control.h"



 void Lock_All_Doors(void)
 {
	 doors_locked = 1;
   Room1_Status = 1;
   Room2_Status = 1;
   Room3_Status = 1;
	 
	 UART0_Output_String("Locking All Doors");
	 UART0_Output_Newline();
	 SysTick_Delay1ms(2000);
	 Play_Note(C4_NOTE, 100);
	 Play_Note(E4_NOTE, 100);
	 Play_Note(G4_NOTE, 200);
	 RGB_LED_Output(RGB_LED_RED);
	 UART0_Output_String("All doors are now LOCKED.");
	 UART0_Output_Newline();
 }
 
  
 void Unlock_All_Doors(void)
 {
	 doors_locked = 0;
	 Room1_Status = 0;
   Room2_Status = 0;
   Room3_Status = 0; 
	 
	 UART0_Output_String("Unlocking All Doors");
	 UART0_Output_Newline();
	 SysTick_Delay1ms(2000);
	 Play_Note(G4_NOTE, 100);
	 Play_Note(E4_NOTE, 100);
	 Play_Note(C4_NOTE, 200);
	 RGB_LED_Output(RGB_LED_GREEN);
	 UART0_Output_String("All doors are now UNLOCKED.");
	 UART0_Output_Newline();
 }
 
 void Check_Room_Status(void)
 {
	 UART0_Output_String("Checking Room Status...");
	 UART0_Output_Newline();
	 SysTick_Delay1ms(2000);
	 
	 if (Room1_Status)
	 {
		 UART0_Output_String("Room 1: LOCKED");
	 }
	 else
	 {
		 UART0_Output_String("Room 1: UNLOCKED");
	 }
	 UART0_Output_Newline();
	 if (Room2_Status)
	 {
		 UART0_Output_String("Room 2: LOCKED");
	 }
	 else
	 {
		 UART0_Output_String("Room 2: UNLOCKED");
	 }
	 UART0_Output_Newline();
	 if (Room3_Status)
	 {
		 UART0_Output_String("Room 3: LOCKED");
	 }
	 else
	 {
		 UART0_Output_String("Room 3: UNLOCKED");
	 }
	 UART0_Output_Newline();
 }
 