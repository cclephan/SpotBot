#include <Arduino.h>
#include <PrintStream.h>
#include "task_spot.h"
#include "shares.h"

Share<bool> spot_me_bro("Spot Trigger");

void task_spot(void* p_params){
    while(1){
        vel1 = vel_queue.get();
        vel2 =
    }
}