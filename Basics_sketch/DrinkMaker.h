/*
  Initialization methods
*/
#ifndef DRINKMAKER_H
#define DRINKMAKER_H

#include <Servo.h>

class DrinkMaker 
{
  public:
      DrinkMaker ();
      int defineCocktail(char *cocktailrequest);
      int createCocktail(int cocktail);  
      int processReceipt(int cocktailReceipt[][2]);  
      void processDrink(int drink[2]);
      void openCloseGap(int drink[], int servoNumber);   
      void initServos();
      void makeMove(Servo servo, int drink[]);

      Servo servo4;
      Servo servo5;
      Servo servo6;
      Servo servo7;
      Servo servo8;
      Servo servo9;
};

#endif
