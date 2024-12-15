/**
 * @file Door_Control.h
 *
 * @brief Header file for functions regarding door status/ unlocking and locking all doors..
 *
 * This file contains the function definitions locking and unlocking doors.
 *
 * @author John Paul D. Cortina/ Adrian Gaspar 
 */
 #include "UART.h"
 #include "SysTick_Delay.h"
 #include "Buzzer.h"
 #include "GPIO.h"
 #include <string.h>
 
 extern uint8_t doors_locked;
 extern uint8_t Room1_Status;
 extern uint8_t Room2_Status;
 extern uint8_t Room3_Status;
 
  /**
 * @brief Lock all doors
 *
 *Locks all the doors and updates the system status accordingly.
 *
 * @param none
 *
 * @return None
 */
 void Lock_All_Doors(void);
 
  /**
 * @brief Unlock all doors
 *
 *Unlocks all the doors and updates the system like the lock function
 *
 * @param none
 *
 * @return None
 */
 void Unlock_All_Doors(void);
 
  /**
 * @brief Room Status
 *
 * brief Checks the status of each individual room's door and displays it.
 *
 * @param none
 *
 * @return None
 */
 void Check_Room_Status(void);
 
 
  /**
 * @brief Door 1 Control
 *
 * Locks or unlocks Door 1 based on the input parameter.
 *
 * @param none
 *
 * @return None
 */
 void Door_1(uint8_t lock);
  /**
 * @brief Door 2 Control
 *
 * Locks or unlocks Door 2 based on the input parameter.
 *
 * @param none
 *
 * @return None
 */
 void Door_2(uint8_t lock);
  /**
 * @brief Door 3 Control
 *
 * Locks or unlocks Door 3 based on the input parameter.
 * @param none
 *
 * @return None
 */
 void Door_3(uint8_t lock);

 /**
 * @brief Process of opening all the doors
 *
 * Displays a menu for opening individual doors and processes user input
 *
 * @param none
 *
 * @return None
 */
void OpenDoors(void);
 /**
 * @brief System of allowing access for open doors
 *
 * Attempts to open a specific door and triggers an alarm if the door is 
 *
 * @param none
 *
 * @return None
 */
void Attempt_To_Open_Door(uint8_t door);
 /**
 * @brief Alarm of unathourized entrance
 *
 * Triggers an alarm for unauthorized access to a specific door.
 *
 * @param none
 *
 * @return None
 */
void Trigger_Alarm(uint8_t door);