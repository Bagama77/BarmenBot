/*
  Receipts of cocktails
*/
#ifndef RECEIPTS2_H
#define RECEIPTS2_H

#include "Arduino.h"
//#include <Servo.h>
//#include <SoftwareSerial.h>



//Definitions of pinouts to drinks
#define  VODKA      4                    //VODKA
#define  TOMATO_DJ  5                //TOMATO DJUCE
#define  TEKILA     6                   //TEKILA
#define  LIME_DJ    7                  //LIME DJUCE
#define  CUANTRO    8                  //CUANTRO
#define  WHISKEY    9                  //WHISKEY

#define RESET_BTN       13
#define SERVO_PIN       12
#define I2C_SPEED       9600
#define SERVO_ANGLE_OFF 0
#define SERVO_ANGLE_ON  45

//Definitions of quantities
#define ML10  2
#define ML15  3
#define ML20  4
#define ML25  5
#define ML30  6
#define ML35  7
#define ML40  8
#define ML45  9
#define ML50  10
#define ML100  20

extern int MARGARITA[3][2] = {{TEKILA, ML30},{LIME_DJ, ML30},{CUANTRO, ML30}};
extern int BLOOD_MARY[3][2] = {{VODKA, ML50},{TOMATO_DJ, ML50}};
extern int WHISKEY50[1][2] = {{WHISKEY, ML50}};
extern int WHISKEY100[1][2] = {{WHISKEY, ML100}};
extern int VODKA50[1][2] = {{VODKA, ML100}}; 
extern int VODKA100[1][2] = {{VODKA, ML50}}; 

//extern SoftwareSerial EEBlue(1, 0); // RX | TX
//extern Servo servo4;
//extern Servo servo5;
//extern Servo servo6;
//extern Servo servo7;
//extern Servo servo8;
//extern Servo servo9;

//Definitions of pinouts to drinks
extern int pinOuts[] = {4,5,6,7,8,9}; //number of pins for drinks


#endif
