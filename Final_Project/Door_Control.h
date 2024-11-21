/**
 * @file Door_Control.h
 *
 * @brief Header file for functions regarding door status/ unlocking and locking all doors..
 *
 * This file contains the function definitions locking and unlocking doors.
 *
 * @author John Paul D. Cortina
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
 
 void Lock_All_Doors(void);
 void Unlock_All_Doors(void);
 void Check_Room_Status(void);