#include <Arduino.h>
#include "PrintStream.h"
#include "motor_driver.h"

#define OUTA 36
#define OUTB 39

bool OUTA_val1 = digitalRead(OUTA);
bool OUTA_val2 = digitalRead(OUTA);
bool OUTB_val1 = digitalRead(OUTB);
int32_t counter = 0;

void update_pos(){
  OUTA_val1 = digitalRead(OUTA);
  if (OUTA_val1 != OUTA_val2){
    if (OUTB_val1 == OUTA_val1){
      counter ++;
    }
    else{
      counter --;
    }
  }
  OUTA_val2 = OUTA_val1;
}



void setup() {
  Serial.begin (115200);
  while (!Serial) 
  {
  }
  MotorDriver motor;
  motor.set_duty(-50);

  //Encoder Setup
  pinMode(OUTA, INPUT);
  pinMode(OUTB, INPUT);

  OUTA_val2 = digitalRead(OUTA);
  attachInterrupt(OUTA, update_pos, CHANGE);
  attachInterrupt(OUTB, update_pos, CHANGE);
}


void loop() {
  vTaskDelay(500);
  Serial << counter << endl;
  // put your main code here, to run repeatedly:
}