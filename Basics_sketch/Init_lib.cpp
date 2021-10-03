#include "Arduino.h"
#include "Init.h"
#include "PrintFormat.h"


void initOutputs(){
  for(int i = 4; i < 11; i++) {
    pinMode(i, OUTPUT);
    Serial.print("The pinout ");
    Serial.print(i);
    Serial.println(" is initialized.");
  }
}

void initResetButton(int button){
  pinMode(button, INPUT);   //input mode
  Serial.print("The reset pin is initialized on the pin .");
  Serial.println(button);
}

void initSerialPort(int baudRate){
  Serial.begin(baudRate);
  Serial.print("The serial port is initialized on the baud rate ");
  Serial.println(baudRate);
}

//void initBluetooth(){
//  EEBlue.begin(definitions2.I2C_SPEED);  //Default Baud for comm, it may be different for your Module. 
//  Serial.println("The bluetooth gates are open.\n Connect to HC-05 from any other bluetooth device with 1234 as pairing key!.");
//}

 // Feed all data from termial to bluetooth
//  if (Serial.available())
//    EEBlue.write(Serial.read());
//  EEBlue.read()
