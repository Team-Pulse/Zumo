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

#if 0 //Week2:Assignment1
    

        void zmain(void){
            
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
    
//ultrasonic sensor//
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
        }
        vTaskDelay(200);
    }
}  

void tank_turn(uint8 l_speed, uint8 r_speed, uint32 delay){
    SetMotors(0,1, l_speed, r_speed, delay);
}


#endif


