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

void JukkisPrint(void){
    printf("Cool story, bro\n");
    
    while(true){
    
        vTaskDelay(100);
    }


}

#if 0

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