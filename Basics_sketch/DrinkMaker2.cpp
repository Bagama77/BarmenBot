/*
  Methods for making cocktails
*/

#include "Arduino.h"
#include <SoftwareSerial.h>
#include "Definitions.h"
#include "PrintFormat.h"
#include "DrinkMaker.h"

Defns definitions;

DrinkMaker::DrinkMaker (){};
int DrinkMaker::defineCocktail(char *cocktailrequest){
  if(cocktailrequest[0] == 'M' && cocktailrequest[1] == 'A' && cocktailrequest[2] == 'R') return 1;
  if(cocktailrequest[0] == 'B' && cocktailrequest[1] == 'L' && cocktailrequest[2] == 'O') return 2;
  if(cocktailrequest[0] == 'W' && cocktailrequest[1] == 'H' && cocktailrequest[7] == '5') return 3;
  if(cocktailrequest[0] == 'W' && cocktailrequest[1] == 'H' && cocktailrequest[7] == '1') return 4;
  if(cocktailrequest[0] == 'V' && cocktailrequest[1] == 'O' && cocktailrequest[5] == '5') return 5;
  if(cocktailrequest[0] == 'V' && cocktailrequest[1] == 'O' && cocktailrequest[5] == '1') return 6;
  return 0;
}
  
  
int DrinkMaker::createCocktail(int cocktail){
  formatPrint("Receipt is ", cocktail, ".");
  int result = 0;
  // choose cocktail receipt
  switch(cocktail) {
    case 1:
      processReceipt(definitions.MARGARITA);
      result = 1;
      break;
    case 2:
      processReceipt(definitions.BLOOD_MARY);
      result = 4;
      break;
    case 3:
      processReceipt(definitions.WHISKEY50);
      result = 2;
      break;
    case 4:
      processReceipt(definitions.WHISKEY100);
      result = 3;
      break;
    case 5:
      processReceipt(definitions.VODKA50);
      result = 5;
      break;
    case 6:
      processReceipt(definitions.VODKA100);
      result = 6;
      break;
    default:
      Serial.println("The cocktail is not exists.");
      break;
  }
  return result;
}
  
  
int DrinkMaker::processReceipt(int cocktailReceipt[][2]){
  int r;
  for(r = 0; r < sizeof(cocktailReceipt)/2; r++) {
    processDrink(cocktailReceipt[r]);
  }

  if(r == sizeof(cocktailReceipt)/2 - 1) return 1;
  else return 0;
}
  
  
void DrinkMaker::processDrink(int drink[2]){
  formatPrint("Start processing the drink ", drink[0], ".");
  if(drink[0] == definitions.VODKA) openCloseGap(drink, 4);
  if(drink[0] == definitions.TOMATO_DJ) openCloseGap(drink, 5);
  if(drink[0] == definitions.TEKILA) openCloseGap(drink, 6);
  if(drink[0] == definitions.LIME_DJ) openCloseGap(drink, 7);
  if(drink[0] == definitions.CUANTRO) openCloseGap(drink, 8);
  if(drink[0] == definitions.WHISKEY) openCloseGap(drink, 9);
  formatPrint("End processing the drink ", drink[0], ".");
}
  
void DrinkMaker::openCloseGap(int drink[], int servoNumber){
//  servo4.write(SERVO_ANGLE_ON); //digitalWrite(drink[0], HIGH);     //open the gap of drink (HIGH outputs 5V)  
  delay(100 * drink[1]);
//  servo4.write(SERVO_ANGLE_OFF); //digitalWrite(drink[0], LOW);
}
      
