/**
 * @file SWORD.c
 *
 * @brief Source code for the SWORD driver.
 *
 * This file contains the definitions of all the functions required for SWORD's functionality.
 *
 * @author John Paul D. Cortina & Adrian Gaspar
 */
 
 #include "SWORD.h"
 
 
 char username[username_length] = "";
 uint8_t doors_locked = 0;
 uint8_t Room1_Status = 0;
 uint8_t Room2_Status = 0;
 uint8_t Room3_Status = 0; 
 
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
	 UART0_Output_String("3. Check Room Status.");
	 UART0_Output_Newline();
	 UART0_Output_String("4. Manage Doors");
	 UART0_Output_Newline();
	 UART0_Output_String("5. Open Doors");
	 UART0_Output_Newline();
	 UART0_Output_String("Select a Choice: ");
	 
	 
	 char user_input = UART0_Input_Character();
	 UART0_Output_Newline();
	 
	 
	 switch (user_input)
	 {
		 case '1':
				Lock_All_Doors();
		 break;
		 case '2':
			 Unlock_All_Doors();
		   break;
		 case '3':
			 Check_Room_Status();
			 break;
		 case '4':
			 IndividualRooms();
		  break;
		 case '5':
			 OpenDoors();
		  break;
		 default:
			 UART0_Output_String("Invalid choice. Please try again.");
			 UART0_Output_Newline();
			 break;
	 }
 }
 
 
 
 void IndividualRooms(void)
 {
	 UART0_Output_String("******** Individual MENU ******");
	 UART0_Output_Newline();
	 UART0_Output_String("1. Lock Door 1");
	 UART0_Output_Newline();
	 UART0_Output_String("2. Unlock Door 1");
	 UART0_Output_Newline();
	 UART0_Output_String("3. Lock Door 2");
	 UART0_Output_Newline();
	 UART0_Output_String("4. Unlock Door 2");
	 UART0_Output_Newline();
	 UART0_Output_String("5. Lock Door 3");
	 UART0_Output_Newline();
	 UART0_Output_String("6. Unlock Door 3");
	 UART0_Output_Newline();
	 UART0_Output_String("7. Return to Main Mennu.");
	 UART0_Output_Newline();
	 UART0_Output_String("Enter Your Choice: ");
	 
	 char user_input = UART0_Input_Character();
	 UART0_Output_Newline();
	 
	  switch (user_input)
	 {
		 case '1':
				Door_1(1);
		 break;
		 case '2':
			 Door_1(0);
		   break;
		 case '3':
			 Door_2(1);
			 break;
		 case '4':
			 Door_2(0);
		  break;
		  case '5':
			 Door_3(1);
		  break;
			 case '6':
			 Door_3(0);
		  break;
			 case '7':
			 return;
		 default:
			 UART0_Output_String("Invalid choice. Please try again.");
			 UART0_Output_Newline();
			 break;
	 }
 }
 
 void OpenDoors(void)
 {
	UART0_Output_String("******** Open Doors ******");
  UART0_Output_Newline();
  UART0_Output_String("1. Open Door 1.");
  UART0_Output_Newline();
  UART0_Output_String("2. Open Door 2.");
  UART0_Output_Newline();
  UART0_Output_String("3. Open Door 3.");
  UART0_Output_Newline();
  UART0_Output_String("4. Return to Main Menu.");
  UART0_Output_Newline();
  UART0_Output_String("Select a Choice: ");
    
  char user_input = UART0_Input_Character();
  UART0_Output_Newline();

  switch (user_input)
  {
		case '1':
       Attempt_To_Open_Door(1);
    break;
    case '2':
       Attempt_To_Open_Door(2);
    break;
    case '3':
       Attempt_To_Open_Door(3);
    break;
    case '4':
    return; // Exit to main menu
    default:
       UART0_Output_String("Invalid choice. Please try again.");
       UART0_Output_Newline();
       break;
    }
}
	 
	 
 