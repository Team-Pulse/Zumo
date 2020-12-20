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

#if 0
void roopePrint(void)
{
    printf("Cool story, jees\n");
    
    while(true)
    {
        vTaskDelay(100); 
    }
}
#endif

#if 1
//IR receiverm - how to wait for IR remote commands
void testausta(void)
{
    IR_Start();
    motor_start();
    printf("\n\nIR test\n");
    
    IR_flush(); // clear IR receive buffer
    printf("Buffer cleared\n");
    
    bool led = false;
    // Toggle led when IR signal is received
    while(true)
    {
        // toggle led state when button is pressed
        if(SW1_Read() == 0) {
            led = !led;
            BatteryLed_Write(led);
            if(led) printf("Led is ON\n");
            else printf("Led is OFF\n");
            Beep(1000, 150);
            motor_forward(10, 500);
            motor_forward(0, 0);
            while(SW1_Read() == 0) vTaskDelay(10); // wait while button is being pressed
        }  
        IR_wait();  // wait for IR command
        led = !led;
        BatteryLed_Write(led);
        if(led) printf("Led is ON\n");
        else printf("Led is OFF\n");
        
        IR_isr_Enable();
        motor_forward(10, 4000); 
        motor_forward(0, 0);      
    }    
 }

void week4assignment1(void)
{
    struct sensors_ sensors_raw;
    struct sensors_ sensors;
    int current_line = 0;
    bool line = false;
    bool done = false;
    
    motor_start();
    printf("Motors started.\n");
    reflectance_start();
    motor_forward(0, 0);
    IR_Start();
    IR_flush();
    
    while(SW1_Read());
    
    vTaskDelay(5000);
    
    while(true)
    {
        reflectance_read(&sensors_raw);
        reflectance_digital(&sensors);
        
        bool is_on_track = sensors.L1 && sensors.R1;
        bool is_on_line = sensors.L3 && sensors.L2 && sensors.R2 && sensors.R3;
        
        printf("%d", current_line);
        
        if(is_on_track && !done)
        {
            motor_forward(10, 0);
        }
        
        if(is_on_line)
        {
            line = true;
        }
        
        if(!is_on_line && line)
        {
            current_line++;
            line = false;
        }
        
        if(current_line == 1)
        {
            motor_forward(0, 0);
            IR_wait();
            motor_forward(10, 0);
            current_line++;
        }
        
        if(current_line == 6)
        {
            motor_forward(0, 0);
            done = true;
        }
    }
}

#define READY "Zumo04/ready"
#define START "Zumo04/start"
#define STOP "Zumo04/stop"
#define TIME "Zumo04/time"

void zumomaze(void)
{
    struct sensors_ sensors_raw;
    struct sensors_ sensors;
    int current_line = 0;
    bool line = false;
    bool done = false;
    Ultra_Start();
    motor_start();
    reflectance_start();
    reflectance_set_threshold(9000, 9000, 11000, 11000, 9000, 9000);
    reflectance_digital(&sensors);
    IR_Start();
    IR_flush();
    int rand();
    
    vTaskDelay(1000);
    
    while (sensors.L3 == 0 && sensors.R3 == 0)
    {
        motor_forward(80, 0);
        reflectance_digital(&sensors);
    }
    
    motor_stop();
    print_mqtt(READY, "maze");
    IR_wait();
    
    TickType_t startTime = xTaskGetTickCount();
    print_mqtt(START, "%d", startTime);
    
    motor_start();
    motor_forward(100,270);
            
    while(true)
    {
        reflectance_read(&sensors_raw);
        reflectance_digital(&sensors);
        
        bool is_on_track = sensors.L1 && sensors.R1;
        bool is_on_obstacle = sensors.L3 && sensors.L2 && sensors.R2 && sensors.R3;
        
        int distance = Ultra_GetDistance();
        
        if(is_on_track && !done)
        {
            motor_forward(10, 0);
        }
        
        if (distance < 0,01)
        {
            motor_forward(0,0);
            vTaskDelay(400);
            motor_forward(100,350);
            
            int direction = rand() % 2; //0 for right and 1 for left
       
            if (direction == 0)
            {
                motor_turn(100,0,525);
            }
            else
            {
                motor_turn(0,100,525);
            }     
        }
        
        
        if(current_line == 0,0)
        {
            motor_forward(0, 0);
            IR_wait();
            motor_forward(10, 0);
            current_line++;
        }
        
        if(current_line == 0,13)
        {
            motor_forward(0, 0);
            done = true;
            
            TickType_t stopTime = xTaskGetTickCount();
            print_mqtt(STOP, "%d", stopTime);
            
            TickType_t runTime = stopTime - startTime;
            print_mqtt(TIME, "%d", runTime);
        }
    }
}
#endif
/* [] END OF FILE */
