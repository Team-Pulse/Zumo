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
            bool on_intersection = sensors.L3 && sensors.L2 && sensors.R2 && sensors.R3;// JOE: why check L2 twice? Did you mean R3
            
            
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
    
#if 0 // Project
    
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
    
    
    int getRefValues (struct sensors_ *sensors, int L3, int L2, int L1, int R1, int R2, int R3);   
    void line_follower(struct sensors_ *sensors);
    
    void zmain (void)
{
     //variables declaration and engine launch
    int lines = 0;
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
        while(lines < 5)
        {
                line_follower(&sensors);
                lines++;
                //Wait for the signal on the first intersection
                if(lines == 1)
                {
                    IR_flush();
                    IR_wait();
                    //turn left on the second intersection
                } else if(lines == 2)
                  {
                    while(!getRefValues(&sensors, 0,0,1,1,0,0))
                    {

                     motor_turn(10,200,10);
                     reflectance_digital(&sensors);
                    }
                    //turn right on the third intersection
                  }else if(lines == 3)
                   {
                    while(!getRefValues(&sensors, 0,0,1,1,0,0))
                    {
                     motor_turn(200,10,10);
                     reflectance_digital(&sensors);
                    }//turn right on the fourth intersection
                   }else if(lines == 4)
                    {
                    while(!getRefValues(&sensors, 0,0,1,1,0,0))
                    {
                     motor_turn(200,10,10);
                     reflectance_digital(&sensors);
                    }
                    }
        }

            //shuttin the system
            motor_stop();
            
            

}

int getRefValues (struct sensors_ *sensors, int L3, int L2, int L1, int R1, int R2, int R3)
{
 if (sensors->L1 == L1 && sensors->L2 == L2 && sensors->L3 == L3 && sensors->R1 == R1 && sensors->R2 == R2 &&sensors->R3 == R3 )
{
   
    return 1;
}else
{
    
    return 0;
}

}

void line_follower(struct sensors_ *sensors)
{ 
     reflectance_digital(sensors);
   //Going through the intersection
    while(getRefValues(sensors, 1, 1,1,1,1,1))
    {
        motor_forward(100,10);
        reflectance_digital(sensors);
    }


    while(!getRefValues(sensors, 1, 1, 1, 1, 1, 1))
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
//Stopping the motors
    motor_forward(0,0);
}

//These functions allow to make a tankturn either left or right:
//200 speed 262 delay is 90 degrees
void tank_turn_right(uint8 speed,uint32 delay){
//   SetMotors(0,0, l_speed, r_speed, delay);
    SetMotors(0,1, speed, speed, delay);
}
void tank_turn_left(uint8 speed,uint32 delay){
//   SetMotors(0,0, l_speed, r_speed, delay);
    SetMotors(1,0, speed, speed, delay);

}


    
#endif


#if 1


#define ON 			1
#define LED_ON 		1
#define FIRST_LINE 	1 
#define SECOND_LINE 2
#define THIRD_LINE 	3
#define FOURTH_LINE 4
#define FIFTH_LINE  5


    void follow_the_line(struct sensors_ *sensors);
	int reflectanceValues (struct sensors_ *sensors, int L3, int L2, int L1, int R1, int R2, int R3);
    
    void Week4_assignment3 (void)
{
    
    int lines = 0;
    struct sensors_ sensors;
    motor_start();
    reflectance_start();
    IR_Start();
    
    //Switching the LED on
        BatteryLed_Write(LED_ON);
        printf("LED status: ON\n");
        printf("Press the blue LED button\n");
        while(SW1_Read() == ON);
        BatteryLed_Write(0);
        vTaskDelay(1000);
        //stop on the last intersection
        while(lines < FIFTH_LINE)
        {
                follow_the_line(&sensors);
                lines++;
                //Wait for the signal on the first intersection
                if(lines == FIRST_LINE)
                {
                    printf("Press the IR button\n");
                    IR_flush();
                    IR_wait();
                    
                } else if(lines == SECOND_LINE)
                  {
                    while(!reflectanceValues(&sensors,0,0,1,1,0,0))
                    {
                     printf("Turning left on second line");
                     motor_turn(10,200,10);
                     reflectance_digital(&sensors);
                    }
                    
                  }else if(lines == THIRD_LINE)
                   {
                    while(!reflectanceValues(&sensors, 0,0,1,1,0,0))
                    {
                        printf("Turning right on third line");
                     motor_turn(200,10,10);
                     reflectance_digital(&sensors);
                    }
                   }else if(lines == FOURTH_LINE)
                    {
                    while(!reflectanceValues(&sensors, 0,0,1,1,0,0))
                    {
                     printf("Turning right on fourth Line");
                     motor_turn(200,10,10);
                     reflectance_digital(&sensors);
                    }
                    }
        }

            
            printf("Shut down");
            motor_stop();
            
            

}

int reflectanceValues (struct sensors_ *sensors, int L3, int L2, int L1, int R1, int R2, int R3){
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
    while(reflectanceValues(sensors, 1, 1,1,1,1,1))
    {
        motor_forward(100,10);
        reflectance_digital(sensors);
    }


    while(!reflectanceValues(sensors, 1, 1, 1, 1, 1, 1))
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
//Stopping the motors
    motor_forward(0,0);
}



//These functions allow to make a tankturn either left or right:
//200 speed 262 delay is 90 degrees
void tank_turn_right(uint8 speed,uint32 delay){
//   SetMotors(0,0, l_speed, r_speed, delay);
    SetMotors(0,1, speed, speed, delay);
}
void tank_turn_left(uint8 speed,uint32 delay){
//   SetMotors(0,0, l_speed, r_speed, delay);
    SetMotors(1,0, speed, speed, delay);

}

#endif