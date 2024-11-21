/**
 * @file SWORD.h
 *
 * @brief Header file for functions regarding SWORD's functionality.
 *
 * This file contains the function definitions for traversing SWORD's UI and menu system allowing
 * the user to control their living space.
 *
 * @author John Paul D. Cortina
 */
 
 #include "UART.h"
 #include <string.h>
 
 
 #define username_length 20
 
 
 /**
 * @brief Function to 
 *
 * Uses the UART function to output a menu terminal for the user
 *
 * @param none
 *
 * @return None
 */
 
void CreateUser(void);
 /**
 * @brief Create SWORD's menu
 *
 * Uses the UART function to output a menu terminal for the user
 *
 * @param none
 *
 * @return None
 */
void DisplayMenu(void);

void Lock_All_Doors(void);
void Unlock_All_Doors(void);