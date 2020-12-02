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
#if 1
#include "Roni.h"
/* [] END OF FILE */

void RoniPrint(void)
{
    printf("Cool story jees\n");
    
    while (true)
    {
     vTaskDelay(100);   
    }
}

// Week 4 Assignment 2
void week4_assignment2(void)
{
    motor_start();
    
    struct sensors_ dig;
    
    reflectance_start();
    reflectance_set_threshold(9000, 9000, 11000, 11000, 9000, 9000);
    
    IR_Start();
    
    while (SW1_Read())
    {
    }
    
    motor_forward(30,0);
        
    while(true)
    {
        reflectance_digital(&dig);
        
        if (dig.L3 || dig.R3 == 1)
        {
            motor_forward(30,150);
            motor_forward(0,0);
            
            IR_wait();
            
            motor_forward(30,1000);
            motor_turn(30, 10, 1600);
            motor_forward(30,1300);
            motor_turn(10, 30, 1600);
            motor_turn(8, 30, 2400);
            motor_forward(30,1200);
            motor_stop();
        }
    }
}

#define TURN "Zumo04/turn"

// Week 5 assignment 2
void week5_assignment2(void)
{
    Ultra_Start();
    motor_start();
    
    while(true)
    {
        int distance = Ultra_GetDistance();
        int rand();
        
        motor_forward(100,0);
        
        if (distance < 5)
        {
            motor_forward(0,0);
            vTaskDelay(400);
            motor_backward(100,350);
            
            int direction = rand() % 2; //0 for right and 1 for left
       
            if (direction == 0)
            {
                print_mqtt(TURN, "Turning right.", direction);
                vTaskDelay(400);
                motor_turn(100,0,525);
            }
            else
            {
                print_mqtt(TURN, "Turning left.", direction);
                vTaskDelay(400);
                motor_turn(0,100,525);
            }     
        }
    }
}

#endif