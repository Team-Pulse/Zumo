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
void week3_assignmen2(void) //Week3 assignment2
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
void week3_assignment3(void)
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

void tank_turn(uint8 l_speed, uint8 r_speed, uint32 delay){
    SetMotors(0,1, l_speed, r_speed, delay);
    r_speed = 20;
}

int random_number(int min, int max)  
                             
{ 
    int distance, anyRandom, x;
    distance = max-min;
    anyRandom = rand();
    
    x = anyRandom % distance;
    return (x+min);
    
    /*From scale 90 degrees - 270 degrees = min 40 -> 120*/
} 

#endif






#if 0 //week4_assignment2
    void zmain(void)

    {
        
        struct sensors_ normal;
        struct sensors_ sensors;
        
        bool line = false;
        bool mission_complete = false;
        bool turning = false;
        int count = 0;
        
        motor_start();
        printf("Motor is on.\n");
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
            bool on_intersection = sensors.L3 && sensors.L2 && sensors.R2 && sensors.R3;
            
            
            printf("The count is: %d\n", count);
            
            
            if(is_on_track && !mission_complete)
            {
                motor_forward(20,0);
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
                
                //This is the issue.
                turning = true;//JOE:you have not defined a variable for turning. 
                while(turning)
                {
                   
                }
                motor_forward(0,0);
                 
            }
            
        }                   
    }
    
    


    
#endif





#if 0 //Week4_Assignment3
    int reflactance_values (struct sensors_ *sensors, int L3, int L2, int L1, int R1, int R2, int R3);   
    void follow_the_line(struct sensors_ *sensors);
    
    void zmain (void)
{
    
    int intersection = 0;
    
    struct sensors_ sensors;
    motor_start();
    reflectance_start();
    IR_Start();
    
    //Switching the LED on
        BatteryLed_Write(1);
        //Starting the function, when the button is pressed
        while(SW1_Read() == 1);
        BatteryLed_Write(0);
        vTaskDelay(1000);
        //stop on the last intersection
        while(intersection < 5)
        {
                follow_the_line(&sensors);
                intersection++;
                //Wait for the signal on the first intersection
                if(intersection == 1)
                {
                    IR_flush();
                    IR_wait();
                    //turn left on the second intersection
                } else if(intersection == 2)
                  {
                    while(!reflactance_values(&sensors, 0,0,1,1,0,0))
                    {
                     
                        
                     motor_turn(10,200,10);
                     reflectance_digital(&sensors);
                     
                    }
                    //turn right on the third intersection
                  }else if(intersection == 3)
                   {
                    while(!reflactance_values(&sensors, 0,0,1,1,0,0))
                    {
                     motor_turn(100,10,10);
                     reflectance_digital(&sensors);
                    }//turn right on the fourth intersection
                   }else if(intersection == 4)
                    {
                    while(!reflactance_values (&sensors, 0,0,1,1,0,0))
                    {
                     motor_turn(200,10,10);
                     reflectance_digital(&sensors);
                    }
                    }
        }

            //shuttin the system
            motor_stop();
            
            

}

int reflactance_values  (struct sensors_ *sensors, int L3, int L2, int L1, int R1, int R2, int R3)
{
    if (sensors->L1 == L1 && sensors->L2 == L2 && sensors->L3 == L3 && sensors->R1 == R1 && sensors->R2 == R2 &&sensors->R3 == R3 )
    {
   
        return 1;
    }else
    {
    
        return 0;
    }

}

void follow_the_line(struct sensors_ *sensors)
{ 
     reflectance_digital(sensors);
   //Going through the intersection
    while(reflactance_values (sensors, 1, 1,1,1,1,1))
    {
        motor_forward(100,10);
        reflectance_digital(sensors);
    }


    while(!reflactance_values (sensors, 1, 1, 1, 1, 1, 1))
    {
        //Left Turn
        while(sensors->R2 == 0 && sensors->L2 == 1)
        {
            tank_turn_left(255,1);
            reflectance_digital(sensors);
        }
        //Right Turn
        while(sensors->R2 == 1 && sensors->L2 == 0)
        {
            tank_turn_right(255, 1);
            reflectance_digital(sensors);
        }
        
        //Left turn over 90 degrees
        while(sensors->R2 == 1 && sensors->R3 == 0 && sensors->L2 == 1 && sensors->L3 == 1)
        {
            tank_turn_left(255, 1);
            reflectance_digital(sensors);
        }
        //Right turn over 90 degrees
         while(sensors->R2 == 1 && sensors->R3 == 1 && sensors->L2 == 1 && sensors->L3 == 0)
        {
            tank_turn_right(255, 1);
            reflectance_digital(sensors);
        }
        motor_forward(200, 10);
        reflectance_digital(sensors);
    }

    motor_forward(0,0);
}


void tank_turn_right(uint8 speed,uint32 delay){
    SetMotors(0,1, speed, speed, delay);
}
void tank_turn_left(uint8 speed,uint32 delay){
    SetMotors(1,0, speed, speed, delay);

}
#endif    

    
#if 0 // WEEK5:Assignment1
    
    
    #define TOPIC "<robot serial number>/button."
 void week5_assignment1(void)
    {
        while(true)
        {
        vTaskDelay(200);
        TickType_t interval_1 = xTaskGetTickCount();
        printf("\nPress the button\n");
        while(SW1_Read());      
        print_mqtt(TOPIC, "TaskGetTickCount(): %d milliseconds", interval_1); 
        
        while(!SW1_Read());
        }
        while(true)
            {
                vTaskDelay(100);            
            }
    }
    
    


    
#endif
    
#if 1 //Line_follower Project Assignment
    
    #define READY "Zumo04/ready"
    #define START "Zumo04/start"
    #define STOP "Zumo04/stop"
    #define TIME "Zumo04/time"
    #define MISS "Zumo04/miss"
    #define LINE "Zumo04/line"
    
    
    int reflactance_values (struct sensors_ *sensors, int L3, int L2, int L1, int R1, int R2, int R3);   
    void track_status(struct sensors_ *sensors);

    
    void zmain (void)
{
    //Variables
    int intersection = 0;
    TickType_t starting_time = 0;
    TickType_t finishing_time = 0;
    TickType_t run_time;
    //Starts the motors and system.
    struct sensors_ sensors;
    motor_start();
    reflectance_start();
    IR_Start();
    
        //Switches the LED on
        BatteryLed_Write(1);
        //Starts the function, when the button is pressed and prints the starting time in milliseconds
        while(SW1_Read() == 1);
        starting_time = xTaskGetTickCount();
        print_mqtt(START, "%d", starting_time);
        
        BatteryLed_Write(0);
        vTaskDelay(1000);
        //stops on the last line
        while(intersection <= 3)
        {
              
                follow_the_line(&sensors);
                intersection++;
                //Waits for the signal on the first line
                if(intersection == 1)
                {
                    print_mqtt(READY, "line");
                    IR_flush();                 
                    IR_wait();                   
                } else if(intersection == 2)
                  {
                     while(reflactance_values (&sensors, 1, 1,1,1,1,1))
                     {
                     motor_forward(100,10);
                     reflectance_digital(&sensors);
                     }                    
                  }else if(intersection == 3)
                   {
                    
                    //Prints the time in milliseconds when the robot has crossed the finish line from the begi
                    finishing_time = xTaskGetTickCount();       
                    print_mqtt(STOP, "%d", finishing_time); 
                    //prints the runtime what is difference of stoptime and starttime
                    run_time = finishing_time - starting_time;
                    print_mqtt(TIME, "%d", run_time);
                    
                        while(!reflactance_values(&sensors, 0,0,1,1,0,0))
                        {
                            reflectance_digital(&sensors);
                        
                        }
                    }
                
        }

}

int reflactance_values  (struct sensors_ *sensors, int L3, int L2, int L1, int R1, int R2, int R3)
{
    if (sensors->L1 == L1 && sensors->L2 == L2 && sensors->L3 == L3 && sensors->R1 == R1 && sensors->R2 == R2 &&sensors->R3 == R3 )
    {
   
        return 1;
    }else
    {
    
        return 0;
    }

}

void follow_the_line(struct sensors_ *sensors)
{ 
     TickType_t *starting_time = starting_time;
     bool on_track = true;     
     reflectance_digital(sensors);
   //Drives through
    while(reflactance_values (sensors, 1, 1,1,1,1,1))
    {
        motor_forward(100,10);
        reflectance_digital(sensors);
        
    }

    while(!reflactance_values (sensors, 1, 1, 1, 1, 1, 1))
    {
        //Turns left when the robot's R2 sensor is off the track
        while(sensors->R2 == 0 && sensors->L2 == 1)
        {
            
            tank_turn_left(255,1);
            reflectance_digital(sensors);
            
        }
        //Turns Right when the robot's L2 sensor is off the track
        while(sensors->R2 == 1 && sensors->L2 == 0)
        {
            
            tank_turn_right(255, 1);
            reflectance_digital(sensors);                                                            
        }
        //Prints "zumo04/miss" when the robot's center sensors are off the track
        if(on_track == true && reflactance_values(sensors, 0,0,0,0,0,0))
        {
            on_track = false;
            print_mqtt(MISS, "%d", starting_time); 
        }
        //Prints "zumo04/line" when robot's center sensors are back on track
        else if(on_track == false && !reflactance_values(sensors, 0,0,0,0,0,0))
        {
            on_track = true;
            print_mqtt(LINE, "%d", starting_time);
        }
        
        motor_forward(200, 10);
        reflectance_digital(sensors);       
    }
        
    motor_forward(0,0);
        
}
     
void tank_turn_right(uint8 speed,uint32 delay){
    SetMotors(0,1, speed, speed, delay);
}
void tank_turn_left(uint8 speed,uint32 delay){
    SetMotors(1,0, speed, speed, delay);

}
#endif