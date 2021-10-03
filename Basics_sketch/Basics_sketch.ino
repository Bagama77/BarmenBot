#include <Servo.h>
//#include <SoftwareSerial.h>
#include "Arduino.h"
#include <stdio.h>
#include "Receipts2.h"
#include "Init.h"
#include "PrintFormat.h"
#include "DrinkMaker.h"
#include "Definitions.h"

Defns definitions2;
DrinkMaker drinkMaker;
char* readTransferedData();

Servo servo4;
Servo servo5;
Servo servo6;
Servo servo7;
Servo servo8;
Servo servo9;

//Initializing peripherals
void setup() {  
    pinMode(LED_BUILTIN, OUTPUT);

  //initialise outputs to drinks
  initOutputs();

  // initialise serial port with baud rate of 9600
  initSerialPort(definitions2.I2C_SPEED);

  //Init of bluetooth
//  initBluetooth();

  //Init reset button
  initResetButton(definitions2.RESET_BTN);

  //Init servos
  initServos();
}


void loop() {

//  if (Serial.available() > 0) {
//    // read the incoming byte:
//    incomingByte = Serial.read();
//    incomingByte2 = Serial.read();
//
//    // say what you got:
//    Serial.print("I received: ");
//    digitalWrite(LED_BUILTIN, HIGH);
//    Serial.println(incomingByte);
//    delay(1000);
//    Serial.println("The cocktail is ready!");
//    digitalWrite(LED_BUILTIN, LOW);
//  }


  char cocktailRequest[11];
  int result = 0;
  
  if (Serial.available() > 0) {
    readTransferedData(cocktailRequest);
    formatPrint("Cocktail request: ", cocktailRequest, " ..");
    int cocktailNumber = drinkMaker.defineCocktail(cocktailRequest);
    result = drinkMaker.createCocktail(cocktailNumber);

    if(result > 0) {
      Serial.println("The cocktail is ready!");
    } else Serial.println("Something went wrong!");
  }
}


void initServos(){
  
  servo4.attach(definitions2.VODKA);
  servo4.write(definitions2.SERVO_ANGLE_OFF);
  formatPrint("The servo ", definitions2.VODKA, " is initialized.");

  servo5.attach(definitions2.TOMATO_DJ);
  servo5.write(definitions2.SERVO_ANGLE_OFF);
  formatPrint("The servo ", definitions2.TOMATO_DJ, " is initialized.");

  servo6.attach(definitions2.TEKILA);
  servo6.write(definitions2.SERVO_ANGLE_OFF);
  formatPrint("The servo ", definitions2.TEKILA, " is initialized.");

  servo7.attach(definitions2.LIME_DJ);
  servo7.write(definitions2.SERVO_ANGLE_OFF);
  formatPrint("The servo ", definitions2.LIME_DJ, " is initialized.");

  servo8.attach(definitions2.CUANTRO);
  servo8.write(definitions2.SERVO_ANGLE_OFF);
  formatPrint("The servo ", definitions2.CUANTRO, " is initialized.");

  servo9.attach(definitions2.WHISKEY);
  servo9.write(definitions2.SERVO_ANGLE_OFF);
  formatPrint("The servo ", definitions2.WHISKEY, " is initialized.");
    
}
