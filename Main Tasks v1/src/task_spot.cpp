#include <Arduino.h>
#include <PrintStream.h>
#include "task_spot.h"
#include "shares.h"

float r_vel;
float l_vel;
uint8_t state = 0;
uint16_t timer_counter = 0;
uint16_t rep_counter = 0;
uint16_t spot_counter = 0;

Share<bool> spot_me_bro("Spot Trigger");

void task_spot(void* p_params){
    while(1){
        r_vel = vel_queue.get();
        l_vel = vel_queue.get();
        if(state == 0){
            timer_counter = 0;
            if(r_vel == 0 && l_vel == 0){
                state = 1;
            }
        }
        if(state == 1){
            Serial << "Bar is racked" << endl;
            if(r_vel < 0 && l_vel < 0){
                state = 2;
            }
            }
        if (state == 2){
            Serial << "Bar is in descent" << endl;
            Serial << timer_counter;
            timer_counter++;
            if ((r_vel < 0.05 && r_vel > -0.05) && (l_vel < 0.05 && l_vel > -0.05)){
                state = 3;
            }
             if(timer_counter >= 10){
                state = 5;
            }           
        }
        if (state == 3){
            Serial << "Bar is stopped at chest" << endl;
            timer_counter++;
            Serial << timer_counter;
            if(r_vel > 0 && l_vel > 0){
                state = 4;
                
            }
            if(timer_counter >= 10){
                state = 5;
            }
        }
        if (state == 4){
            Serial << "Bar is going up" << endl;
            timer_counter++;
            Serial << timer_counter;
            if (r_vel == 0 && l_vel == 0){
                rep_counter++;
                Serial << "Nice bench bro you've done " << rep_counter << " rep(s)" << endl;
                state = 1;
            }
            if(timer_counter >= 10){
                state = 5;
            }
        }
        if (state == 5){
            spot_counter++;
            Serial << "Rep failed spotting initiated" << endl;
            if(spot_counter >= 6){
                spot_me_bro.put(0);
            }
            else{
                spot_me_bro.put(1);
            }
        }
        vTaskDelay(50);
    }
}