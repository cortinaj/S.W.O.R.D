/**
 * @file SWORD.c
 *
 * @brief Source code for the SWORD driver.
 *
 * This file contains the definitions of all the functions required for SWORD's functionality.
 *
 * @author John Paul D. Cortina
 */
 
 #include "SWORD.h"
 #include "Buzzer.h"
 
 char username[username_length] = "";
 uint8_t doors_locked = 0;
 
 void CreateUser(void)
 {
	 char input[username_length];
	 
	 //Prompt the user to create a username
	 UART0_Output_String("Enter your username: ");
	 UART0_Input_String(input, username_length);
	 UART0_Output_Newline();
	 
	 //Copy username into global variable
	 strncpy(username, input, username_length -1);
	 //Ensures there is a null termination
	 username[username_length - 1] = '\0'; 
	 UART0_Output_String("New user created! Welcome, ");
	 UART0_Output_String(username);
	 UART0_Output_Newline();
 }
 
 void DisplayMenu(void)
 {
	 
	 UART0_Output_String("******** SWORD MENU ******");
	 UART0_Output_Newline();
	 UART0_Output_String("1. Lock all doors.");
	 UART0_Output_Newline();
	 UART0_Output_String("2. Unlock all doors.");
	 UART0_Output_Newline();
	 UART0_Output_String("3. Check Door Status.");
	 UART0_Output_Newline();
	 
	 char user_input = UART0_Input_Character();
	 
	 switch (user_input)
	 {
		 case '1':
			 Lock_All_Doors();
			 break;
		 case '2':
			 Unlock_All_Doors();
		   break;
		 case '3':
			 UART0_Output_String("Exiting menu.");
			 UART0_Output_Newline();
			 break;
		 default:
			 UART0_Output_String("Invalid choice. Please try again.");
			 UART0_Output_Newline();
			 break;
	 }
 }
 
 void Lock_All_Doors(void)
 {
	 doors_locked = 1;
	 
	 Play_Note(C4_NOTE, 100);
	 Play_Note(E4_NOTE, 100);
	 Play_Note(G4_NOTE, 200);
	 UART0_Output_String("All doors are now LOCKED.");
	 UART0_Output_Newline();
 }
 
 void Unlock_All_Doors(void)
 {
	 doors_locked = 0;
	 
	 Play_Note(G4_NOTE, 100);
	 Play_Note(E4_NOTE, 100);
	 Play_Note(C4_NOTE, 200);
	 UART0_Output_String("All doors are now UNLOCKED.");
	 UART0_Output_Newline();
 }