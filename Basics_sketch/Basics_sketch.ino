#include <Servo.h>
#include <SoftwareSerial.h>
#include "Arduino.h"
#include <stdio.h>
#include "Receipts2.h"
#include "Init.h"
#include "PrintFormat.h"
#include "DrinkMaker.h"
#include "Definitions.h"

Defns definitions2;
DrinkMaker drinkMaker;
extern SoftwareSerial EEBlue(1, 0); // RX | TX
char* readTransferedData();

Servo servo4;
Servo servo5;
Servo servo6;
Servo servo7;
Servo servo8;
Servo servo9;


//Initializing peripherals
void setup() {  

  //initialise outputs to drinks
  initOutputs();

  // initialise serial port with baud rate of 9600
  initSerialPort(definitions2.I2C_SPEED);

  //Init of bluetooth
  initBluetooth();

  //Init reset button
  initResetButton(definitions2.RESET_BTN);

  //Init servos
  initServos();
}


void loop() {
  char *cocktailRequest;
  int result = 0;
  // Feed any data from bluetooth to Terminal.
  if (EEBlue.available()) {
    cocktailRequest = readTransferedData();
    formatPrint("Cocktail request: ", cocktailRequest, " ..");
    int cocktailNumber = drinkMaker.defineCocktail(cocktailRequest);
    result = drinkMaker.createCocktail(cocktailNumber);
  }

  if(result > 0) {
    Serial.println("The cocktail is ready!");
  } else Serial.println("Something went wrong!");

}

//int defineCocktail(char *cocktailrequest) {
//  if(cocktailrequest[0] == 'M' && cocktailrequest[1] == 'A' && cocktailrequest[2] == 'R') return 1;
//  if(cocktailrequest[0] == 'B' && cocktailrequest[1] == 'L' && cocktailrequest[2] == 'O') return 2;
//  if(cocktailrequest[0] == 'W' && cocktailrequest[1] == 'H' && cocktailrequest[7] == '5') return 3;
//  if(cocktailrequest[0] == 'W' && cocktailrequest[1] == 'H' && cocktailrequest[7] == '1') return 4;
//  if(cocktailrequest[0] == 'V' && cocktailrequest[1] == 'O' && cocktailrequest[5] == '5') return 5;
//  if(cocktailrequest[0] == 'V' && cocktailrequest[1] == 'O' && cocktailrequest[5] == '1') return 6;
//  return 0;
//}

//int createCocktail(int cocktail){
//  formatPrint("Receipt is ", cocktail, ".");
//  int result = 0;
//  // choose cocktail receipt
//  switch(cocktail) {
//    case 1:
//      processReceipt(MARGARITA);
//      result = 1;
//      break;
//    case 2:
//      processReceipt(BLOOD_MARY);
//      result = 4;
//      break;
//    case 3:
//      processReceipt(WHISKEY50);
//      result = 2;
//      break;
//    case 4:
//      processReceipt(WHISKEY100);
//      result = 3;
//      break;
//    case 5:
//      processReceipt(VODKA50);
//      result = 5;
//      break;
//    case 6:
//      processReceipt(VODKA100);
//      result = 6;
//      break;
//    default:
//      Serial.println("The cocktail is not exists.");
//      break;
//  }
//  return result;
//}


//int processReceipt(int cocktailReceipt[][2]){
//  int r;
//  for(r = 0; r < sizeof(cocktailReceipt)/2; r++) {
//    processDrink(cocktailReceipt[r]);
//  }
//
//  if(r == sizeof(cocktailReceipt)/2 - 1) return 1;
//  else return 0;
//}


//void processDrink(int drink[2]){
//  formatPrint("Start processing the drink ", drink[0], ".");
//  if(drink[0] == VODKA) openCloseGap(drink, 4);
//  if(drink[0] == TOMATO_DJ) openCloseGap(drink, 5);
//  if(drink[0] == TEKILA) openCloseGap(drink, 6);
//  if(drink[0] == LIME_DJ) openCloseGap(drink, 7);
//  if(drink[0] == CUANTRO) openCloseGap(drink, 8);
//  if(drink[0] == WHISKEY) openCloseGap(drink, 9);
//  formatPrint("End processing the drink ", drink[0], ".");
//}

//void openCloseGap(int drink[], int servoNumber){
////  servo4.write(SERVO_ANGLE_ON); //digitalWrite(drink[0], HIGH);     //open the gap of drink (HIGH outputs 5V)  
//  delay(100 * drink[1]);
////  servo4.write(SERVO_ANGLE_OFF); //digitalWrite(drink[0], LOW);
//}

char* readTransferedData(){
  char result[11];
  int counter = 0;
  while (Serial.available()) {
    delay(10);  //small delay to allow input buffer to fill

    char c = Serial.read();  //gets one byte from serial buffer
    if (c == '.') {
      break;
    }  //breaks out of capture loop to print readstring
    result[counter] = c;
    counter++; 
  } //makes the string readString  

  if (sizeof(result) > 0) {
    Serial.println(result); //prints string to serial port out
  }
  return result;
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

void initBluetooth(){
  EEBlue.begin(definitions2.I2C_SPEED);  //Default Baud for comm, it may be different for your Module. 
  Serial.println("The bluetooth gates are open.\n Connect to HC-05 from any other bluetooth device with 1234 as pairing key!.");
}

 // Feed all data from termial to bluetooth
//  if (Serial.available())
//    EEBlue.write(Serial.read());
//  EEBlue.read()
