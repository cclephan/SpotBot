#include "motor_driver.h"
#include "task_motor.h"
#include "PrintStream.h"
#include "shares.h"

uint8_t state = 0;
MotorDriver motor;
bool spot = 0;

void task_motor(void* p_params){
    while(1){
        spot = spot_me_bro.get();
        if (state == 0){
            if(spot){
                motor.set_duty(128);
                state = 1;
            }
        }
        if (state == 1){
            Serial << "Motor Spinning" << endl;
            if(!spot){
                motor.stop();
                state = 0;
            }
        }
        vTaskDelay(50);
    }

}