#include <Servo.h>
#include <SoftwareSerial.h>
#include "Arduino.h"
#include <stdio.h>
#include "Receipts2.h"


extern SoftwareSerial EEBlue(1, 0); // RX | TX
char* readTransferedData();
void openCloseGap(int drink[], int servoNumber);
//Servo servo4, servo5, servo6, servo7, servo8, servo9;
//int pinOuts[] = {4,5,6,7,8,9}; //number of pins for drinks

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
  initSerialPort();

  //Init of bluetooth
  initBluetooth();

  //Init reset button
  initResetButton();

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
    int cocktailNumber = defineCocktail(cocktailRequest);
    result = createCocktail(cocktailNumber);
  }

  if(result > 0) {
    Serial.println("The cocktail is ready!");
  } else Serial.println("Something went wrong!");

}

int defineCocktail(char *cocktailrequest) {
  if(cocktailrequest[0] == 'M' && cocktailrequest[1] == 'A' && cocktailrequest[2] == 'R') return 1;
  if(cocktailrequest[0] == 'B' && cocktailrequest[1] == 'L' && cocktailrequest[2] == 'O') return 2;
  if(cocktailrequest[0] == 'W' && cocktailrequest[1] == 'H' && cocktailrequest[7] == '5') return 3;
  if(cocktailrequest[0] == 'W' && cocktailrequest[1] == 'H' && cocktailrequest[7] == '1') return 4;
  if(cocktailrequest[0] == 'V' && cocktailrequest[1] == 'O' && cocktailrequest[5] == '5') return 5;
  if(cocktailrequest[0] == 'V' && cocktailrequest[1] == 'O' && cocktailrequest[5] == '1') return 6;
  return 0;
}

int createCocktail(int cocktail){
  formatPrint("Receipt is ", cocktail, ".");
  int result = 0;
  // choose cocktail receipt
  switch(cocktail) {
    case 1:
      processReceipt(MARGARITA);
      result = 1;
      break;
    case 2:
      processReceipt(BLOOD_MARY);
      result = 4;
      break;
    case 3:
      processReceipt(WHISKEY50);
      result = 2;
      break;
    case 4:
      processReceipt(WHISKEY100);
      result = 3;
      break;
    case 5:
      processReceipt(VODKA50);
      result = 5;
      break;
    case 6:
      processReceipt(VODKA100);
      result = 6;
      break;
    default:
      Serial.println("The cocktail is not exists.");
      break;
  }
  return result;
}


int processReceipt(int cocktailReceipt[][2]){
  int r;
  for(r = 0; r < sizeof(cocktailReceipt)/2; r++) {
    processDrink(cocktailReceipt[r]);
  }

  if(r == sizeof(cocktailReceipt)/2 - 1) return 1;
  else return 0;
}


void processDrink(int drink[2]){
  formatPrint("Start processing the drink ", drink[0], ".");
  if(drink[0] == VODKA) openCloseGap(drink, 4);
  if(drink[0] == TOMATO_DJ) openCloseGap(drink, 5);
  if(drink[0] == TEKILA) openCloseGap(drink, 6);
  if(drink[0] == LIME_DJ) openCloseGap(drink, 7);
  if(drink[0] == CUANTRO) openCloseGap(drink, 8);
  if(drink[0] == WHISKEY) openCloseGap(drink, 9);
  formatPrint("End processing the drink ", drink[0], ".");
}

void openCloseGap(int drink[], int servoNumber){
//  servo4.write(SERVO_ANGLE_ON); //digitalWrite(drink[0], HIGH);     //open the gap of drink (HIGH outputs 5V)  
  delay(100 * drink[1]);
//  servo4.write(SERVO_ANGLE_OFF); //digitalWrite(drink[0], LOW);
}

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

void initOutputs(){
  for(int i = 4; i<11; i++) {
    pinMode(pinOuts[i], OUTPUT);
    formatPrint("The pinout ", i, " is initialized.");
  }
}

void initServos(){
  
  servo4.attach(VODKA);
  servo4.write(SERVO_ANGLE_OFF);
  formatPrint("The servo ", VODKA, " is initialized.");

  servo5.attach(TOMATO_DJ);
  servo5.write(SERVO_ANGLE_OFF);
  formatPrint("The servo ", TOMATO_DJ, " is initialized.");

  servo6.attach(TEKILA);
  servo6.write(SERVO_ANGLE_OFF);
  formatPrint("The servo ", TEKILA, " is initialized.");

  servo7.attach(LIME_DJ);
  servo7.write(SERVO_ANGLE_OFF);
  formatPrint("The servo ", LIME_DJ, " is initialized.");

  servo8.attach(CUANTRO);
  servo8.write(SERVO_ANGLE_OFF);
  formatPrint("The servo ", CUANTRO, " is initialized.");

  servo9.attach(WHISKEY);
  servo9.write(SERVO_ANGLE_OFF);
  formatPrint("The servo ", WHISKEY, " is initialized.");
    
}

void initResetButton(){
  pinMode(RESET_BTN, INPUT);   //input mode
  Serial.println("The reset pin is initialized.");
}

void initBluetooth(){
  EEBlue.begin(I2C_SPEED);  //Default Baud for comm, it may be different for your Module. 
  Serial.println("The bluetooth gates are open.\n Connect to HC-05 from any other bluetooth device with 1234 as pairing key!.");
}

void initSerialPort(){
  Serial.begin(I2C_SPEED);
  Serial.println("The serial port is initialized.");
}

void formatPrint( char *leftStr, int MyVar1, char *sepStr) {
  Serial.print (leftStr);
  Serial.print (MyVar1);
  Serial.print (sepStr);
}


void formatPrint( char *leftStr, char *myStr, char *sepStr) {
  Serial.print (leftStr);
  Serial.print (myStr);
  Serial.print (sepStr);
}


 // Feed all data from termial to bluetooth
//  if (Serial.available())
//    EEBlue.write(Serial.read());
//  EEBlue.read()
