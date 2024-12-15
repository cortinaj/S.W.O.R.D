 /**
 * @file Door_Control.c
 *
 * @brief Source code for controlling door status.
 *
 * This file contains the definitions of all the functions required for checking and maintaing door status.
 *
 * @author John Paul D. Cortina / Adrian Gaspar
 */
 #include "Door_Control.h"

#include "SysTick_Delay.h"

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
	 EduBase_LEDs_Output(EDUBASE_LED_ALL_ON);
	 UART0_Output_String("All doors are now LOCKED.");
	 UART0_Output_Newline();
 }
 
  void Door_1(uint8_t lock)
 {
	 uint8_t current_led_state = GPIOB -> DATA & 0x0F;
	 if(lock) {
		 
   Room1_Status = 1;
   
	 
	 UART0_Output_String("Door 1 Locked");
	 UART0_Output_Newline();
	 SysTick_Delay1ms(2000);
	 Play_Note(C4_NOTE, 200);
	 SysTick_Delay1ms(50);
	 Play_Note(D4_NOTE, 200);
	 SysTick_Delay1ms(50);
	 Play_Note(G4_NOTE, 200);
	 SysTick_Delay1ms(50);
	 EduBase_LEDs_Output(current_led_state | 0x01);

 }
	 else{
		 
	Room1_Status = 0;
		  
	 UART0_Output_String("Door 1 Unlocked");
	 UART0_Output_Newline();
	 SysTick_Delay1ms(2000);
	 
	 Play_Note(G4_NOTE, 200);
   SysTick_Delay1ms(50);
	 Play_Note(D4_NOTE, 200);
	 SysTick_Delay1ms(50);
	 Play_Note(C4_NOTE, 200);
	 SysTick_Delay1ms(50);
	 
	 EduBase_LEDs_Output(current_led_state & ~0x01);
	
	 }
 }	 
 
  void Door_2(uint8_t lock)
 {
	 uint8_t current_led_state = GPIOB -> DATA & 0x0F;
	 if(lock) {
		 
   Room2_Status = 1;
   
	 
	 UART0_Output_String("Door 2 Locked");
	 UART0_Output_Newline();
	 SysTick_Delay1ms(2000);
	 Play_Note(C4_NOTE, 200);
	 SysTick_Delay1ms(50);
	 Play_Note(D4_NOTE, 200);
	 SysTick_Delay1ms(50);
	 Play_Note(G4_NOTE, 200);
	 SysTick_Delay1ms(50);
	 EduBase_LEDs_Output(current_led_state | 0x02);

 }
	 else{
		 
	Room2_Status = 0;
		 
	 UART0_Output_String("Door 2 Unlocked");
	 UART0_Output_Newline();
	 SysTick_Delay1ms(2000);
	 
	 Play_Note(G4_NOTE, 200);
   SysTick_Delay1ms(50);
	 Play_Note(D4_NOTE, 200);
	 SysTick_Delay1ms(50);
	 Play_Note(C4_NOTE, 200);
	 SysTick_Delay1ms(50);
	 
	 EduBase_LEDs_Output(current_led_state & ~0x02);
	 }
 }	
 
   void Door_3(uint8_t lock)
 {
	 uint8_t current_led_state = GPIOB -> DATA & 0x0F;
	 if(lock) {
		 
   Room3_Status = 1;
   
	 
	 UART0_Output_String("Door 3 Locked");
	 UART0_Output_Newline();
	 SysTick_Delay1ms(2000);
	 Play_Note(C4_NOTE, 200);
	 SysTick_Delay1ms(50);
	 Play_Note(D4_NOTE, 200);
	 SysTick_Delay1ms(50);
	 Play_Note(G4_NOTE, 200);
	 SysTick_Delay1ms(50);
	 EduBase_LEDs_Output(current_led_state | 0x04);

 }
	 else{
		 
		Room3_Status = 0;
		 
	 UART0_Output_String("Door 3 Unlocked");
	 UART0_Output_Newline();
	 SysTick_Delay1ms(2000);
	 
	 Play_Note(G4_NOTE, 200);
   SysTick_Delay1ms(50);
	 Play_Note(D4_NOTE, 200);
	 SysTick_Delay1ms(50);
	 Play_Note(C4_NOTE, 200);
	 SysTick_Delay1ms(50);
	 
	 EduBase_LEDs_Output(current_led_state & ~0x04);
	
	 }
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
	 EduBase_LEDs_Output(EDUBASE_LED_ALL_OFF);
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
 
 void Attempt_To_Open_Door(uint8_t door)
 {
	 uint8_t is_locked = 0;
	 
	 switch(door)
	 {
		 case 1:
			 is_locked = Room1_Status;
		 break;
		 case 2:
			 is_locked = Room2_Status;
		 break;
		 case 3:
			 is_locked = Room3_Status;
		 break;
		 default:
			 UART0_Output_String("Invalid door selected.");
		   UART0_Output_Newline();
		    return;
	 }
	 
	 if(is_locked)
	 {
		 UART0_Output_String("ALARM! Unauthorized access detected.");
     UART0_Output_Newline();
     Trigger_Alarm(door);
	 }
	 else
	 {
		  UART0_Output_String("Door successfully opened.");
      UART0_Output_Newline();
    }
 }
 
 void Trigger_Alarm(uint8_t door)
{
    UART0_Output_String("ALARM! Unauthorized access detected on Door ");
    UART0_Output_Character('0' + door);
    UART0_Output_Newline();

    // Flash LEDs and play alarm sound
    for (int i = 0; i < 5; i++) // Flash 5 times
    {
        if (door == 1) EduBase_LEDs_Output(0x01); // Flash LED1
        else if (door == 2) EduBase_LEDs_Output(0x02); // Flash LED2
        else if (door == 3) EduBase_LEDs_Output(0x04); // Flash LED3

        SysTick_Delay1ms(200); // LED ON for 200ms
        EduBase_LEDs_Output(0x00); // LED OFF
        SysTick_Delay1ms(200); 
    }

    // Play alarm sound
    Play_Note(C4_NOTE, 300);
    SysTick_Delay1ms(50);
    Play_Note(E4_NOTE, 300);
    SysTick_Delay1ms(50);
    Play_Note(G4_NOTE, 500);
}

 