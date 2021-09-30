/*
  Initialization methods
*/
#ifndef DRINKMAKER_H
#define DRINKMAKER_H

class DrinkMaker 
{
  public:
      DrinkMaker ();
      int defineCocktail(char *cocktailrequest);
      int createCocktail(int cocktail);  
      int processReceipt(int cocktailReceipt[][2]);  
      void processDrink(int drink[2]);
      void openCloseGap(int drink[], int servoNumber);   
};

#endif
