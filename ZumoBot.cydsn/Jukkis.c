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
#include "Jukkis.h"
/* [] END OF FILE */

#if 0
void JukkisPrint(void){
    printf("Cool story, bro\n");
    
    while(true){
    
        vTaskDelay(100);
    }


}
#endif

#if 0 //Week3:Assignment1
    

        void Wee3_Assignment1(void){
            
            motor_start();
            motor_forward(0,0);
            motor_forward(100,3500);
            motor_forward(0,0);
            motor_turn(200, 0, 260);
            motor_forward(0,0);
            motor_forward(100,2800);
            motor_turn(200, 0, 260);
            motor_forward(100,2700);
            motor_turn(200, 0, 260);
            motor_forward(0,0);
            motor_turn(100, 80, 2500);
            motor_forward(100,900);
            motor_stop();
            
            while(true)
            {
                vTaskDelay(100);
            
            }
        
        }
        
#endif

        

#if 0
void zmain(void) //Week3 assignment2
{
    Ultra_Start();    // Ultra Sonic Start function
    motor_start();
    vTaskDelay(100);

    while(true) {
        int d = Ultra_GetDistance();
        motor_forward(100,1);
        // Print the detected distance (centimeters)
        printf("distance = %d\r\n", d);
        if (d < 10){
            motor_forward(0,0);
            vTaskDelay(1000);
            motor_backward(100, 1000);
        }
        vTaskDelay(200);
    }
}  

#endif  

#if 0
    
//week3 assignment3
void zmain(void)
{
    Ultra_Start();    // Ultra Sonic Start function
    motor_start();
    vTaskDelay(100);

    while(true) {
        int d = Ultra_GetDistance();
        motor_forward(100,1);
        // Print the detected distance (centimeters)
        printf("distance = %d\r\n", d);
        if (d < 10){
            motor_forward(0,0);
            vTaskDelay(1000);
            motor_backward(100, 1000);
            tank_turn(random_number(40, 120),20,1000);
        }
        vTaskDelay(200);
    }
}  
#if 1
void tank_turn(uint8 l_speed, uint8 r_speed, uint32 delay){
    SetMotors(0,1, l_speed, r_speed, delay);
    r_speed = 20;
}
#endif
int random_number(int min, int max)  
                             
{ 
    int distance, anyRandom, x;
    distance = max-min;
    anyRandom = rand();
    
    x = anyRandom % distance;
    return (x+min);
    
    /*From scale 90* - 270 * = min 40 -> 120*/
} 

#endif

#if 0
    
      void zmain(void)
    {

    struct sensors_ dig;
    _Bool black = 0;
    _Bool on_white = 0;
    int count = 0;

        
 
    
    motor_start();
    IR_Start();
    reflectance_start();
    reflectance_set_threshold(14000, 9000, 11000, 11000, 9000, 14000); // set center sensor threshold to 11000 and others to 9000
    
    vTaskDelay(1000);
    
    motor_forward(10, 0);
    
    reflectance_digital(&dig); //Reads the sensors
    

    
    while(true){
    on_white = 1;
    while(on_white){
        reflectance_digital(&dig);//use always inside a while loop  
        on_white = dig.L3 == 0 && dig.R3 == 0;
        //If stopped before the line
    }
    
    
    black = 1;
    while(black){
        reflectance_digital(&dig);
        black = dig.L3 || dig.R3;
        //If stopped after the line
    }
    }
    
    count++;
    motor_forward(0,0);
    printf("the count is: %d", count);
    
    IR_wait();
    motor_forward(10,0);

    }
    
    

#endif


#if 0 
    void zmain(void)
    {
        #define COUNT 5;
        struct sensors_ normal;
        struct sensors_ sensors;
        
        bool line = false;
        bool done = false;
        int count = 0;
        
        motor_start();
        printf("Motor start\n");
        reflectance_start();
        motor_forward(0,0);
        IR_Start();
        
        while(SW1_Read());
        BatteryLed_Write(1);
        vTaskDelay(1000);
        BatteryLed_Write(0);
        
        motor_forward(10,100);
        
        while(true)
        {
            reflectance_read(&normal);
            reflectance_digital(&sensors);
            
            bool is_on_track = sensors.L1 && sensors.R1;
            bool on_intersection = sensors.L3 && sensors.L2 && sensors.R2 && sensors.L2;
            
            printf("The count is: %d\n", count);
            
            
            if(is_on_track && !done)
            {
                motor_forward(10,0);
            }
            if(on_intersection)
            {
                line = true;
            }
            if(!on_intersection && line)
            {
                count++;
                line = false;
            }
            if(count == 2)
            {
                motor_forward(0,100);
                printf("Waiting IR signal\n");
                IR_wait();
                printf("IR signal recieved. Turning left...\n");
                motor_turn(0, 50, 10000);
                
                
                
            }
            if (count == 3)
            {
                motor_forward(0,0);
                done = true;
            }
        }                   
    }
    


    
#endif