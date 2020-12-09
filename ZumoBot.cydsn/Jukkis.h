/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include <project.h>
#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "Motor.h"
#include "Ultra.h"
#include "Nunchuk.h"
#include "Reflectance.h"
#include "Gyro.h"
#include "Accel_magnet.h"
#include "LSM303D.h"
#include "IR.h"
#include "Beep.h"
#include "mqtt_sender.h"
#include <time.h>
#include <sys/time.h>
#include "serial1.h"
#include <unistd.h>
#include <stdlib.h> 
#include <time.h> 

void JukkisPrint(void);


void tank_turn(uint8 l_speed, uint8 r_speed, uint32 delay);

int random_number(int min, int max);  
void follow_the_line(struct sensors_ *sensors);
int reflectanceValues (struct sensors_ *sensors, int L3, int L2, int L1, int R1, int R2, int R3);
void tank_turn_right(uint8 speed,uint32 delay);
void tank_turn_left(uint8 speed,uint32 delay);
/* [] END OF FILE */