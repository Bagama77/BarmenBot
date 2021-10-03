//#include <SoftwareSerial.h>
#include "Arduino.h"
#include <stdio.h>
#include "Init.h"
#include "PrintFormat.h"
#include "DrinkMaker.h"
#include "Definitions.h"

Defns definitions2;
DrinkMaker drinkMaker;
char* readTransferedData();

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
  drinkMaker.initServos();
}


void loop() {

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
