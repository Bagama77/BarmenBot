
/*
  Defs
*/
#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include "Arduino.h"

class Defns {
  public:
          //Definitions of pinouts to drinks
          int VODKA     =4;                   //VODKA
          int TOMATO_DJ = 5;                   //TOMATO DJUCE
          int TEKILA    = 6;                   //TEKILA
          int LIME_DJ   = 7;                   //LIME DJUCE
          int CUANTRO   = 8;                   //CUANTRO
          int WHISKEY   = 9;                   //WHISKEY

          int RESET_BTN       = 13;
          int I2C_SPEED       = 9600;
          int SERVO_ANGLE_OFF = 0;
          int SERVO_ANGLE_ON  = 45;

          //Definitions of quantities
          int ML10 = 2;
          int ML15 = 3;
          int ML20 = 4;
          int ML25 = 5;
          int ML30 = 6;
          int ML35 = 7;
          int ML40 = 8;
          int ML45 = 9;
          int ML50 = 10;
          int ML100 = 20;

          //Receipts
          int MARGARITA[3][2] = {{TEKILA, ML30},{LIME_DJ, ML30},{CUANTRO, ML30}};
          int BLOOD_MARY[3][2] = {{VODKA, ML50},{TOMATO_DJ, ML50}};
          int WHISKEY50[1][2] = {{WHISKEY, ML50}};
          int WHISKEY100[1][2] = {{WHISKEY, ML100}};
          int VODKA50[1][2] = {{VODKA, ML100}}; 
          int VODKA100[1][2] = {{VODKA, ML50}}; 

};

#endif
