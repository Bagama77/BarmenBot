#include "Arduino.h"
#include "Init.h"
#include "PrintFormat.h"


void initOutputs(){
  for(int i = 4; i < 11; i++) {
    pinMode(i, OUTPUT);
    Serial.print("The pinout ");
    Serial.print("i, ");
    Serial.println("is initialized.");
  }
}

void initResetButton(int button){
  pinMode(button, INPUT);   //input mode
  Serial.println("The reset pin is initialized.");
}

void initSerialPort(int baudRate){
  Serial.begin(baudRate);
  Serial.println("The serial port is initialized.");
}
