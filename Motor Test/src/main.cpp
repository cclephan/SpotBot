#include <Arduino.h>
#include "PrintStream.h"

#define INB1 13
#define INB2 27
#define PWMB 14

#define OUTA 36
#define OUTB 39

#define MAX_PWM 255

void setup() {
  Serial.begin (115200);
  while (!Serial) 
  {
  }
  //Motor Setup
  pinMode(INB1, OUTPUT);
  digitalWrite(INB1, HIGH);

  pinMode(INB2, OUTPUT);
  digitalWrite(INB2, LOW);

  pinMode(PWMB, OUTPUT);

  Serial << "That's one spinny boi" << endl;

  //Encoder Setup
  pinMode(OUTA, INPUT);
  pinMode(OUTB, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(PWMB, 0);
  vTaskDelay(2000);
  analogWrite(PWMB, 0);
  vTaskDelay(2000);
}